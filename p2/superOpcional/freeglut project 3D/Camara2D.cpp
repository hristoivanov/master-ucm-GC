#include "Camara2D.h"

Camara2D::Camara2D() {
	eye = new PuntoVector3D(.0f, .0f, .0f, 1.0f);
	look = new PuntoVector3D(1.0f, .0f, .0f, 1.0f);
	up = new PuntoVector3D(.0f, 1.0f, .0f, .0f);

	left = -10; right = -left; bottom = -10; top = -bottom;
	Near = 1; Far = 40;

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
	glOrtho(left, right, bottom, top, Near, Far);

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