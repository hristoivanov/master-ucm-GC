#include "Camara2D.h"

Camara2D::Camara2D() {
	eye = new PuntoVector3D(-20.0f, 10.0f, .0f, 1);
	look = new PuntoVector3D(-19.9f, 10.0f, .0f, 1);
	up = new PuntoVector3D(.0f, 1.0f, .0f, 0);

	left = -10; right = -left; bottom = 0; top = 20;
	Near = 1; Far = 45;
	fovy = 60; aspect = 1.0f;

	setView();
	setProjection();
	setCameraCoordinateSystem();
}

void Camara2D::setView() {
	//Define la matriz de vista con el comando gluLookAt()     
	//TO DO
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye->getX(), eye->getY(), eye->getZ(), look->getX(), look->getY(), look->getZ(), up->getX(), up->getY(), up->getZ());
}

void Camara2D::setCameraCoordinateSystem() {
	//Obtiene el valor de los vectores u, v, n  
	//TO DO
	n = eye->clonar();
	n->restar(look);
	n->normalizar();
	u = up->productoVectorial(n);
	u->normalizar();
	v = n->productoVectorial(u);

	setModelViewMatrix();
}

void Camara2D::setProjection() {
	//Define la matriz de proyección con el comando 
	//glOrtho() o glFrustum()/gluPerspective()	 
	//TO DO
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(left, right, bottom, top, Near, Far);
	gluPerspective(fovy, aspect, Near, Far);
}

void Camara2D::setModelViewMatrix() {
	glMatrixMode(GL_MODELVIEW);
	GLfloat m[16];
	m[0] = u->getX(); m[4] = u->getY(); m[8] = u->getZ(); m[12] = -eye->productoEscalar(u);
	m[1] = v->getX(); m[5] = v->getY(); m[9] = v->getZ(); m[13] = -eye->productoEscalar(v);
	m[2] = n->getX(); m[6] = n->getY(); m[10] = n->getZ(); m[14] = -eye->productoEscalar(n);
	m[3] = 0; m[7] = 0; m[11] = 0; m[15] = 1;
	glLoadMatrixf(m);
}

void Camara2D::moveForward(){
	PuntoVector3D* aux = look->clonar();
	aux->restar(eye);
	aux->sumar(look);
	eye->setX(look->getX()); eye->setY(look->getY()); eye->setZ(look->getZ());
	look->setX(aux->getX()); look->setY(aux->getY()); look->setZ(aux->getZ());

	setView();
	setCameraCoordinateSystem();
}

void Camara2D::rotate(float ang) {
	GLfloat cs = cos(ang / 180.0f * 3.1415f);
	GLfloat sn = sin(ang / 180.0f * 3.1415f);

	PuntoVector3D* aux = look->clonar();
	aux->restar(eye);

	aux->setX(aux->getX() * cs - aux->getZ() * sn);
	aux->setZ(aux->getX() * sn + aux->getZ() * cs);

	aux->sumar(eye);

	look->setX(aux->getX()); look->setY(aux->getY()); look->setZ(aux->getZ());

	setView();
	setCameraCoordinateSystem();
}

Simple2D* Camara2D::get2D(){
	PuntoVector3D* aux = look->clonar();
	aux->restar(eye);
	aux->normalizar();

	GLfloat ang = fovy / 2.0f;
	GLfloat cs = cos(ang / 180.0f * 3.1415f);
	GLfloat sn = sin(ang / 180.0f * 3.1415f);

	GLfloat farHypotenuse = Far / cs;
	GLfloat nearHypotenuse = Near / cs;

	PuntoVector3D* aux0 = aux->clonar();
	aux0->setX(aux0->getX() * cs - aux0->getZ() * sn);
	aux0->setZ(aux0->getX() * sn + aux0->getZ() * cs);

	aux0->normalizar();
	aux0->escalar(farHypotenuse);
	PuntoVector3D* p0 = eye->clonar();
	p0->sumar(aux0);

	aux0->normalizar();
	aux0->escalar(nearHypotenuse);
	PuntoVector3D* p1 = eye->clonar();
	p1->sumar(aux0);

	aux0 = aux->clonar();
	aux0->setX(aux0->getX() * cs - aux0->getZ() * -sn);
	aux0->setZ(aux0->getX() * -sn + aux0->getZ() * cs);

	aux0->normalizar();
	aux0->escalar(farHypotenuse);
	PuntoVector3D* p3 = eye->clonar();
	p3->sumar(aux0);

	aux0->normalizar();
	aux0->escalar(nearHypotenuse);
	PuntoVector3D* p2 = eye->clonar();
	p2->sumar(aux0);

	PuntoVector3D** pff = new PuntoVector3D*[4];
	pff[0] = p0;
	pff[1] = p1;
	pff[2] = p2;
	pff[3] = p3;

	Simple2D* to_return = new Simple2D(pff, 4);

	return to_return;
}