 #include "Camara.h"

Camara::Camara() {           
	eye=new PuntoVector3D(30, 30, 30, 1);
    look=new PuntoVector3D(0, 0, 0, 1);
    up=new PuntoVector3D(0, 1, 0, 0);
       
    left=-10; right=-left; bottom=-10; top=-bottom; 
	Near=1; Far=1000;
	fovy=25; aspect=1.1; 
	  
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
	n->restar(look);
	n->normalizar();
	u = up->productoVectorial(n);
	u->normalizar();
	v = n->productoVectorial(u);

	setModelViewMatrix();
}

void Camara::setProjection() {
	//Define la matriz de proyección con el comando 
	//glOrtho() o glFrustum()/gluPerspective()	 
	//TO DO
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(proyection)
		glOrtho(left, right, bottom, top, Near, Far);
	else
		gluPerspective(fovy,aspect,Near,Far);

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
	//Gira la cámara alrededor del eje X sobre un plano perpendicular a este eje
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
	//Gira la cámara alrededor del eje Y sobre un plano perpendicular a este eje
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
	//Gira la cámara alrededor del eje Z sobre un plano perpendicular a este eje
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
	up->setX(0);
	up->setY(1);
	GLdouble radio = sqrt(+(eye->getX() * eye->getX()) + (eye->getY() * eye->getY()) + (eye->getZ() * eye->getZ()));
	eye->setX(radio);
	eye->setY(0.0f);
	eye->setZ(0.0f);
	setView();
	setCameraCoordinateSystem();
}

void Camara::frontal() {
	up->setX(0);
	up->setY(1);
	GLdouble radio = sqrt(+(eye->getX() * eye->getX()) + (eye->getY() * eye->getY()) + (eye->getZ() * eye->getZ()));
	eye->setZ(radio);
	eye->setX(0.0f);
	eye->setY(0.0f);
	setView();
	setCameraCoordinateSystem();
}

void Camara::cenital() {
	up->setX(1);
	up->setY(0);
	GLdouble radio = sqrt(+(eye->getX() * eye->getX()) + (eye->getY() * eye->getY()) + (eye->getZ() * eye->getZ()));
	eye->setY(radio);
	eye->setX(0.0f);
	eye->setZ(0.0f);
	setView();
	setCameraCoordinateSystem();
}

void Camara::rincon() {
	up->setX(0);
	up->setY(1);
	GLdouble radio = sqrt(+(eye->getX() * eye->getX()) + (eye->getY() * eye->getY()) + (eye->getZ() * eye->getZ()));
	GLdouble aux = sqrt((radio*radio)/3.0f);
	eye->setX(aux);
	eye->setY(aux);
	eye->setZ(aux);
	setView();
	setCameraCoordinateSystem();
}

void Camara::roll(float ang) {
	//Rota la cámara tal como se explica en las transparencias
	//TO DO
	GLdouble cs = cos(ang / 180.0f * 3.1415f);
	GLdouble sn = sin(ang / 180.0f * 3.1415f);
	v->setX(cs*v->getX() - sn*u->getX());
	v->setY(cs*v->getY() - sn*u->getY());
	v->setZ(cs*v->getZ() - sn*u->getZ());
	v->normalizar();
	u->setX(cs*u->getX() + sn*v->getX());
	u->setY(cs*u->getY() + sn*v->getY());
	u->setZ(cs*u->getZ() + sn*v->getZ());
	u->normalizar();

    setModelViewMatrix();
}

void Camara::pitch(float ang) {		
	GLdouble cs = cos(ang / 180.0f * 3.1415f);
	GLdouble sn = sin(ang / 180.0f * 3.1415f);
	v->setX(cs*v->getX() + sn*n->getX());
	v->setY(cs*v->getY() + sn*n->getY());
	v->setZ(cs*v->getZ() + sn*n->getZ());
	v->normalizar();
	n->setX(cs*n->getX() - sn*v->getX());
	n->setY(cs*n->getY() - sn*v->getY());
	n->setZ(cs*n->getZ() - sn*v->getZ());
	n->normalizar();

	setModelViewMatrix();
}

void Camara::yaw(float ang) {		
	GLdouble cs = cos(ang / 180.0f * 3.1415f);
	GLdouble sn = sin(ang / 180.0f * 3.1415f);
	u->setX(cs*u->getX() - sn*n->getX());
	u->setY(cs*u->getY() - sn*n->getY());
	u->setZ(cs*u->getZ() - sn*n->getZ());
	v->normalizar();
	n->setX(cs*n->getX() + sn*u->getX());
	n->setY(cs*n->getY() + sn*u->getY());
	n->setZ(cs*n->getZ() + sn*u->getZ());
	n->normalizar();

	setModelViewMatrix();
}

void Camara::changeProyection(){
	proyection = !proyection;
	setProjection();
}

void Camara::zoom(float amount){
	right *= amount; left *= amount; top *= amount; bottom *= amount;
	fovy *= amount;
	setProjection();
}


