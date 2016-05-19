#include "Faro.h"

Faro::Faro(GLenum lisghtId) {
	this->lightId = lisghtId;
	this->v = new float[4]();
	v[0] = 0.0f; v[1] = 0.0f; v[2] = 0.0f; v[3] = 1.0f;
	this->dir = new float[3]();
	dir[0] = 0.0f;dir[1] = 0.0f; dir[2] = -1.0f;

	this->amb = new float[4]();
	amb[0] = 1.0f; amb[1] = 1.0f; amb[2] = 1.0f; amb[3] = 1.0f;
	this->esp = new float[4]();
	esp[0] = 1.0f; esp[1] = 1.0f; esp[2] = 1.0f; esp[3] = 1.0f; 
	this->dif = new float[4]();
	dif[0] = 1.0f; dif[1] = 1.0f; dif[2] = 1.0f; dif[3] = 1.0f;

	this->ang = 45.0f;

	glEnable(this->lightId);
	glLightfv(this->lightId, GL_DIFFUSE, this->dif);
	glLightfv(this->lightId, GL_SPECULAR, this->esp);
	glLightf(this->lightId, GL_SPOT_CUTOFF, ang);
}

void Faro::_dibuja(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glMultMatrixf(this->mT->m);
		glLightfv(this->lightId, GL_POSITION, this->v);
		glLightfv(this->lightId, GL_SPOT_DIRECTION, this->dir);
	glPopMatrix();
}

void Faro::setAng(GLfloat ang){
	this->ang = ang;
	glLightf(this->lightId, GL_SPOT_CUTOFF, ang);
}

void Faro::setAmb(GLfloat r, GLfloat g, GLfloat b){
	this->amb[0] = r; this->amb[1] = g; this->amb[2] = b;
	glLightfv(this->lightId, GL_AMBIENT, this->amb);
}

void Faro::setDif(GLfloat r, GLfloat g, GLfloat b){
	this->dif[0] = r; this->dif[1] = g; this->dif[2] = b;
	glLightfv(this->lightId, GL_DIFFUSE, this->dif);
}

void Faro::setEsp(GLfloat r, GLfloat g, GLfloat b){
	this->esp[0] = r; this->esp[1] = g; this->esp[2] = b;
	glLightfv(this->lightId, GL_SPECULAR, this->esp);
}

void Faro::apagar(){
	glDisable(this->lightId);
}

void Faro::encender(){
	glEnable(this->lightId);
}
