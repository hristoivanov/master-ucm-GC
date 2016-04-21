#include "Cubo.h"

Cubo::Cubo() {
	//trash
	numeroElementos = 3;
	elemento = new Elemento*[numeroElementos];

	elemento[0] = new Cilindro(1.0, 4, 4);
	elemento[0]->setPosicion(0.0, 0.0, -0.5);
	elemento[0]->setEscalado(1 / sqrtf(2.0), 1 / sqrtf(2.0), 1.0);
	elemento[0]->setColor(this->color[0], this->color[1], this->color[2]);

	elemento[1] = new Disco(0, 4, 4);
	elemento[1]->setPosicion(0.0, 0.0, -0.5);
	elemento[1]->setEscalado(1 / sqrtf(2.0), 1 / sqrtf(2.0), 1.0);
	elemento[1]->setColor(this->color[0], this->color[1], this->color[2]);

	elemento[2] = new Disco(0, 4, 4);
	elemento[2]->setEscalado(1 / sqrtf(2.0), 1 / sqrtf(2.0), 1.0);
	elemento[2]->setPosicion(0.0, 0.0, 0.5);
	elemento[2]->setColor(this->color[0], this->color[1], this->color[2]);

	for (int i = 0; i<numeroElementos; i++) {
		elemento[i]->setRotacion(0, 0, 45);
	}
}

void Cubo::setColor(GLfloat red, GLfloat green, GLfloat blue){
	for (int i = 0; i<numeroElementos; i++) {
		elemento[i]->setColor(red, green, blue);
	}
}