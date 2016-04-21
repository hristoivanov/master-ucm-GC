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
	glTranslatef(posicion[0], posicion[1], posicion[2]);
	glRotatef(rotacion[0], 1.0f, 0.0f, 0.0f);
	glRotatef(rotacion[1], 0.0f, 1.0f, 0.0f);
	glRotatef(rotacion[2], 0.0f, 0.0f, 1.0f);
	glScalef(escalado[0], escalado[1], escalado[2]);

	glColor3f(color[0], color[1], color[2]);
	gluQuadricDrawStyle(disco, GLU_FILL);
	gluDisk(disco, radioInner, 1.0, slices, rings);
	glPopMatrix();
}