#include "Esfera.h"

Esfera::Esfera(GLint meridianos, GLint paralelos) {
	this->meridianos = meridianos;
	this->paralelos = paralelos;

	this->esfera = gluNewQuadric();
}

void Esfera::dibuja(){
	glPushMatrix();
	glTranslatef(posicion[0], posicion[1], posicion[2]);
	glRotatef(rotacion[0], 1.0f, 0.0f, 0.0f);
	glRotatef(rotacion[1], 0.0f, 1.0f, 0.0f);
	glRotatef(rotacion[2], 0.0f, 0.0f, 1.0f);
	glScalef(escalado[0], escalado[1], escalado[2]);

	glColor3f(color[0], color[1], color[2]);
	gluQuadricDrawStyle(esfera, GLU_FILL);
	gluSphere(esfera, 1.0, meridianos, paralelos);
	glPopMatrix();
}