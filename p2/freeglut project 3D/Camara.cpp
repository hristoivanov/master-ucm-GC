 
#include "Camara.h"

Camara::Camara() {           
	eye=new PuntoVector3D(30, 30, 30, 1);
    look=new PuntoVector3D(0, 0, 0, 1);
    up=new PuntoVector3D(0, 1, 0, 0);
       
    left=-10; right=-left; bottom=-10; top=-bottom; 
	Near=1; Far=1000;
	fovy=5; aspect=2.5; 
	  
	setView();  
	setProjection();
	setCameraCoordinateSystem();		     
}

void Camara::setView() {
	//Define la matriz de vista con el comando gluLookAt()     
	//TO DO
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye->getX(), eye->getY(), eye->getZ(), look->getX(), look->getY(), look->getZ(), up->getX(), up->getY(), up->getZ());
}

void Camara::setCameraCoordinateSystem() {
	//Obtiene el valor de los vectores u, v, n  
	//TO DO
	n = eye->clonar();
	n->sumar(look);
	n->normalizar();
	u = up->productoVectorial(n);
	u->normalizar();
	v = n->productoVectorial(u);

	setModelViewMatrix();
}

void Camara::setProjection() {
	//Define la matriz de proyecci�n con el comando 
	//glOrtho() o glFrustum()/gluPerspective()	 
	//TO DO		 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(left, right, bottom, top, Near, Far);
}

void Camara::setModelViewMatrix() {
    glMatrixMode(GL_MODELVIEW);		 
    GLfloat m[16];  
    m[0]=u->getX(); m[4]=u->getY(); m[8]=u->getZ(); m[12]=-eye->productoEscalar(u);
    m[1]=v->getX(); m[5]=v->getY(); m[9]=v->getZ(); m[13]=-eye->productoEscalar(v);
    m[2]=n->getX(); m[6]=n->getY(); m[10]=n->getZ(); m[14]=-eye->productoEscalar(n);
    m[3]=0; m[7]=0; m[11]=0; m[15]=1;
    glLoadMatrixf(m); 
}

void Camara::giraX() {
	//Gira la c�mara alrededor del eje X sobre un plano perpendicular a este eje
	//TO DO
	//calculamos el radio
	GLdouble radio = sqrt((eye->getY() * eye->getY()) + (eye->getZ() * eye->getZ()));
	//sacamos el angulo
	GLdouble angulo = atan2(eye->getY(), eye->getZ());
	//restamos 0.05 radianes
	angulo -= 0.05;
	//calculamos el nuevo Z
	eye->setZ(cos(angulo) * radio);
	//calculamos el nuevo Y
	eye->setY(sin(angulo) * radio);
    setView();
    setCameraCoordinateSystem();     
}

void Camara::giraY() {
	//Gira la c�mara alrededor del eje Y sobre un plano perpendicular a este eje
	//TO DO
	//calculamos el radio
	GLdouble radio = sqrt((eye->getX() * eye->getX()) + (eye->getZ() * eye->getZ()));
	//sacamos el angulo
	GLdouble angulo = atan2(eye->getX(), eye->getZ());
	//restamos 0.05 radianes
	angulo -= 0.05;
	//calculamos el nuevo Z
	eye->setZ(cos(angulo) * radio);
	//calculamos el nuevo X
	eye->setX(sin(angulo) * radio);
	//actualizamos la matriz de vista
	setView();
	setCameraCoordinateSystem();
}

void Camara::giraZ() {
	//Gira la c�mara alrededor del eje Z sobre un plano perpendicular a este eje
	//TO DO
	//calculamos el radio
	GLdouble radio = sqrt((eye->getY() * eye->getY()) + (eye->getX() * eye->getX()));
	//sacamos el angulo
	GLdouble angulo = atan2(eye->getY(), eye->getX());
	//sumamos 0.05 radianes
	angulo += 0.05;
	//calculamos el nuevo Z
	eye->setX(cos(angulo) * radio);
	//calculamos el nuevo X
	eye->setY(sin(angulo) * radio);
	//actualizamos la matriz de vista
	setView();
	setCameraCoordinateSystem();
}

void Camara::lateral() {
	//Coloca la c�mara de forma que se muestra una visi�n lateral 
	//de la escena (desde el eje X) 
	//TO DO
}

void Camara::frontal() {
	//Coloca la c�mara de forma que se muestra una visi�n frontal 
	//de la escena (desde el eje Z)  
	//TO DO
}

void Camara::cenital() {
    //Coloca la c�mara de forma que se muestra una visi�n cenital 
	//de la escena (desde el eje Y) 
	//TO DO
}

void Camara::rincon() {
    //Coloca la c�mara de forma que se muestra
	//la escena en un rinc�n
	//TO DO
}
 
void Camara::roll(float ang) {
	//Rota la c�mara tal como se explica en las transparencias
	//TO DO	 
    setModelViewMatrix();
}

void Camara::pitch(float ang) {		
    //TO DO
}

void Camara::yaw(float ang) {		
    //TO DO
}
