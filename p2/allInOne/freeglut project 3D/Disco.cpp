#include "Disco.h"

Disco::Disco(GLdouble radioInner, GLint slices, GLint rings) {
	this->radioInner = radioInner;
	this->slices = slices;
	this->rings = rings;

	this->disco = gluNewQuadric();
}

void Disco::dibuja(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glMultMatrixf(this->mT->m);
		glColor3f(color[0], color[1], color[2]);
		gluQuadricDrawStyle(disco, GLU_FILL);
		gluDisk(disco, radioInner, 1.0, slices, rings);
	glPopMatrix();
}