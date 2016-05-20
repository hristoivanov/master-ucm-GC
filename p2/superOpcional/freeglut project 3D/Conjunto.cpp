#include "Conjunto.h"
 
Conjunto::Conjunto() {}

Conjunto::~Conjunto() {
	for (int i=0; i<numeroElementos; i++)
		delete elemento[i];
	delete[] elemento;
}

void Conjunto::dibuja() {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(posicion[0], posicion[1], posicion[2]);
	glRotatef(rotacion[0], 1.0f, 0.0f, 0.0f );
	glRotatef(rotacion[1], 0.0f, 1.0f, 0.0f );
	glRotatef(rotacion[2], 0.0f, 0.0f, 1.0f );
	glScalef(escalado[0], escalado[1], escalado[2]);

	for (int i=0; i<numeroElementos; i++) {
		elemento[i]->dibuja();
	}
	glPopMatrix();
}