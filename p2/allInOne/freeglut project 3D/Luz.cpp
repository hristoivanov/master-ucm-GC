#include "Luz.h"

Luz::Luz(GLenum lisghtId) {
	this->lightId = lisghtId;
	this->v = new float[4]();
	v[0] = 0.0f; v[1] = 0.0f; v[2] = 0.0f; v[3] = 1.0f;

	this->amb = new float[4]();
	amb[0] = 0.2f; amb[1] = 0.0f; amb[2] = 0.2f; amb[3] = 1.0f;
	this->dif = new float[4]();
	dif[0] = 0.1f; dif[1] = 0.0f; dif[2] = 1.0f; dif[3] = 1.0f;
	this->esp = new float[4]();
	esp[0] = 0.0f; esp[1] = 0.0f; esp[2] = 0.0f; esp[3] = 1.0f;

	glEnable(this->lightId);
	glLightfv(this->lightId, GL_AMBIENT, this->amb);
	glLightfv(this->lightId, GL_DIFFUSE, this->dif);
	glLightfv(this->lightId, GL_SPECULAR, this->esp);
}

void Luz::_dibuja(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glMultMatrixf(this->mT->m);
		glLightfv(this->lightId, GL_POSITION, this->v);
	glPopMatrix();
}

void Luz::setAmb(GLfloat r, GLfloat g, GLfloat b){
	this->amb[0] = r; this->amb[1] = g; this->amb[2] = b;
	glLightfv(this->lightId, GL_DIFFUSE, this->amb);
}

void Luz::setDif(GLfloat r, GLfloat g, GLfloat b){
	this->dif[0] = r; this->dif[1] = g; this->dif[2] = b;
	glLightfv(this->lightId, GL_DIFFUSE, this->dif);
}

void Luz::setEsp(GLfloat r, GLfloat g, GLfloat b){
	this->esp[0] = r; this->esp[1] = g; this->esp[2] = b;
	glLightfv(this->lightId, GL_SPECULAR, this->esp);
}

void Luz::apagar(){
	glDisable(this->lightId);
}

void Luz::encender(){
	glEnable(this->lightId);
}
