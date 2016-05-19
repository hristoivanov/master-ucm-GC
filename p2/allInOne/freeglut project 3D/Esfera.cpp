#include "Esfera.h"

Esfera::Esfera(GLint meridianos, GLint paralelos) {
	this->meridianos = meridianos;
	this->paralelos = paralelos;

	this->esfera = gluNewQuadric();
}

void Esfera::dibuja(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glMultMatrixf(this->mT->m);
		glColor3f(color[0], color[1], color[2]);
		gluQuadricDrawStyle(esfera, GLU_FILL);
		gluSphere(esfera, 1.0, meridianos, paralelos);
	glPopMatrix();
}