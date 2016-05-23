#include "TAfin.h"

TAfin::TAfin(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
		glGetFloatv(GL_MODELVIEW_MATRIX, m);
	glPopMatrix();
	posicion = new float[3]();
	rotacion = new float[3]();
	escalado = new float[3]();
	escalado[0] = 1.0f; escalado[1] = 1.0f; escalado[2] = 1.0f;
}

void TAfin::postmultiplica(GLfloat* m1){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadMatrixf(m);
		glMultMatrixf(m1);
		glGetFloatv(GL_MODELVIEW_MATRIX, m);
	glPopMatrix();
}

void TAfin::traslada(PuntoVector3D* v){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
		glTranslatef(v->getX(), v->getY(), v->getZ());
		GLfloat m1[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, m1);
	glPopMatrix();
	postmultiplica(m1);
}

void TAfin::rota(GLfloat angulo, PuntoVector3D* v){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
		glRotatef(angulo, v->getX(), v->getY(), v->getZ());
		GLfloat m1[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, m1);
	glPopMatrix();
	postmultiplica(m1);
}
void TAfin::escala(PuntoVector3D* v){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
		glScalef(v->getX(), v->getY(), v->getZ());
		GLfloat m1[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, m1);
	glPopMatrix();
	postmultiplica(m1);
}

void TAfin::setTraslada(GLfloat x, GLfloat y, GLfloat z){
	this->posicion[0] = x;
	this->posicion[1] = y;
	this->posicion[2] = z;
	this->applyTransforms();
}
void TAfin::setRota(GLfloat x, GLfloat y, GLfloat z){
	this->rotacion[0] = x;
	this->rotacion[1] = y;
	this->rotacion[2] = z;
	this->applyTransforms();
}
void TAfin::setEscala(GLfloat x, GLfloat y, GLfloat z){
	this->escalado[0] = x;
	this->escalado[1] = y;
	this->escalado[2] = z;
	this->applyTransforms();
}

void TAfin::applyTransforms(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
		glTranslatef(posicion[0], posicion[1], posicion[2]);
		glRotatef(rotacion[0], 1.0f, 0.0f, 0.0f);
		glRotatef(rotacion[1], 0.0f, 1.0f, 0.0f);
		glRotatef(rotacion[2], 0.0f, 0.0f, 1.0f);
		glScalef(escalado[0], escalado[1], escalado[2]);
		glGetFloatv(GL_MODELVIEW_MATRIX, m);
	glPopMatrix();
}

GLfloat* TAfin::getTraslada(){
	return posicion;
}

GLfloat* TAfin::getRota(){
	return rotacion;
}

GLfloat* TAfin::getEscala(){
	return escalado;
}