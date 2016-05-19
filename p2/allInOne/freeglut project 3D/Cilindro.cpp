#include "Cilindro.h"

Cilindro::Cilindro(GLdouble topRadio, GLint slices, GLint stacks) {
	this->topRadio = topRadio;
	this->slices = slices;
	this->stacks = stacks;

	this->cilindro = gluNewQuadric();
}

void Cilindro::dibuja(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glMultMatrixf(this->mT->m);
		glColor3f(color[0], color[1], color[2]);
		gluQuadricDrawStyle(cilindro, GLU_FILL);
		gluCylinder(cilindro, 1.0, topRadio,1.0, slices, stacks);
	glPopMatrix();
}