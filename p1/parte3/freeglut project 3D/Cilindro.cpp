#include "Cilindro.h"

Cilindro::Cilindro(GLdouble topRadio, GLint slices, GLint stacks) {
	this->topRadio = topRadio;
	this->slices = slices;
	this->stacks = stacks;

	this->cilindro = gluNewQuadric();
}

void Cilindro::dibuja(){
	glPushMatrix();
	glTranslatef(posicion[0], posicion[1], posicion[2]);
	glRotatef(rotacion[0], 1.0f, 0.0f, 0.0f);
	glRotatef(rotacion[1], 0.0f, 1.0f, 0.0f);
	glRotatef(rotacion[2], 0.0f, 0.0f, 1.0f);
	glScalef(escalado[0], escalado[1], escalado[2]);

	glColor3f(color[0], color[1], color[2]);
	gluQuadricDrawStyle(cilindro, GLU_FILL);
	gluCylinder(cilindro, 1.0, topRadio,1.0, slices, stacks);
	glPopMatrix();
}