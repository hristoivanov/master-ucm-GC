#include "Objeto3D.h"
 
Objeto3D::Objeto3D(){
	color = new float[3]();
	mT = new TAfin();
}

Objeto3D::~Objeto3D(){
	delete(mT);
}

void Objeto3D::setColor(GLfloat red, GLfloat green, GLfloat blue){
	color[0] = red;
	color[1] = green;
	color[2] = blue;
}

void Objeto3D::dibuja() {}
void Objeto3D::_dibuja() {}

void Objeto3D::traslada(PuntoVector3D* v){
	mT->traslada(v);
}

void Objeto3D::rota(GLfloat angulo, PuntoVector3D* v){
	mT->rota(angulo, v);
}

void Objeto3D::escala(PuntoVector3D* v){
	mT->escala(v);
}

void Objeto3D::setTraslada(GLfloat x, GLfloat y, GLfloat z){
	mT->setTraslada(x, y, z);
}

void Objeto3D::setRota(GLfloat x, GLfloat y, GLfloat z){
	mT->setRota(x, y, z);
}

void Objeto3D::setEscala(GLfloat x, GLfloat y, GLfloat z){
	mT->setEscala(x, y, z);
}

GLfloat* Objeto3D::getTraslada(){
	return mT->getTraslada();
}

GLfloat* Objeto3D::getRota(){
	return mT->getRota();
}

GLfloat* Objeto3D::getEscala(){
	return mT->getEscala();
}