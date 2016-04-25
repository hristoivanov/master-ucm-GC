#include "Cubo.h"

Cubo::Cubo() {
	numHijos = 3;
	hijos = new Objeto3D*[numHijos];

	hijos[0] = new Cilindro(1.0, 4, 4);
	hijos[0]->mT->setTraslada(0.0, 0.0, -0.5);
	hijos[0]->mT->setEscala(1 / sqrtf(2.0), 1 / sqrtf(2.0), 1.0);
	hijos[0]->setColor(this->color[0], this->color[1], this->color[2]);

	hijos[1] = new Disco(0, 4, 4);
	hijos[1]->mT->setTraslada(0.0, 0.0, -0.5);
	hijos[1]->mT->setEscala(1 / sqrtf(2.0), 1 / sqrtf(2.0), 1.0);
	hijos[1]->setColor(this->color[0], this->color[1], this->color[2]);

	hijos[2] = new Disco(0, 4, 4);
	hijos[2]->mT->setTraslada(0.0, 0.0, 0.5);
	hijos[2]->mT->setEscala(1 / sqrtf(2.0), 1 / sqrtf(2.0), 1.0);
	hijos[2]->setColor(this->color[0], this->color[1], this->color[2]);

	for (int i = 0; i<numHijos; i++) {
		hijos[i]->mT->setRota(0, 0, 45);
	}
}

void Cubo::setColor(GLfloat red, GLfloat green, GLfloat blue){
	for (int i = 0; i<numHijos; i++) {
		hijos[i]->setColor(red, green, blue);
	}
}