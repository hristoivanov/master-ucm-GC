#include "Coche.h"

Coche::Coche() {
	//trash

	numeroElementos = 7;
	elemento = new Elemento*[numeroElementos];

	elemento[0] = new Cubo();
	//elemento[0]->setRotacion(0.0, 0.0, 0.0);
	elemento[0]->setEscalado(3, 3, 3);
	elemento[0]->setColor(.6f, .0f, .6f);

	elemento[1] = new Rueda();
	elemento[1]->setPosicion(1.5, -1.5, 1.5);

	elemento[2] = new Rueda();
	elemento[2]->setPosicion(-1.5, -1.5, 1.5);

	elemento[3] = new Rueda();
	elemento[3]->setRotacion(0.0, 180.0, 0.0);
	elemento[3]->setPosicion(-1.5, -1.5, -1.5);

	elemento[4] = new Rueda();
	elemento[4]->setRotacion(0.0, 180.0, 0.0);
	elemento[4]->setPosicion(1.5, -1.5, -1.5);

	elemento[5] = new Cilindro(1.7, 10, 10);
	elemento[5]->setEscalado(.2f, .2f, 1.0f);
	elemento[5]->setRotacion(0.0, 90, 0.0);
	elemento[5]->setPosicion(1.5, 0.0, -0.5);
	elemento[5]->setColor(.0f, 1.0f, .0f);

	elemento[6] = new Cilindro(1.7, 10, 10);
	elemento[6]->setEscalado(.2f, .2f, 1.0f);
	elemento[6]->setRotacion(0.0, 90, 0.0);
	elemento[6]->setPosicion(1.5, 0.0, 0.5);
	elemento[6]->setColor(.0f, 1.0f, .0f);

}

void Coche::avanza(GLfloat f){
	this->posicion[0] = this->posicion[0] + f;

	elemento[1]->rotacion[2] = elemento[1]->rotacion[2] - (f / 3.14f) * 180.0f;
	elemento[2]->rotacion[2] = elemento[2]->rotacion[2] - (f / 3.14f) * 180.0f;
	elemento[3]->rotacion[2] = elemento[3]->rotacion[2] + (f / 3.14f) * 180.0f;
	elemento[4]->rotacion[2] = elemento[4]->rotacion[2] + (f / 3.14f) * 180.0f;

}