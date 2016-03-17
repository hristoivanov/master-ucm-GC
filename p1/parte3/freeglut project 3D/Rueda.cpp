#include "Rueda.h"

Rueda::Rueda() {
	//trash
	numeroElementos = 2;
	elemento = new Elemento*[numeroElementos];

	elemento[0] = new Cilindro(1.0, 8, 8);
	elemento[0]->setPosicion(0.0, 0.0, -0.5);

	elemento[1] = new Disco(0, 8, 8);
	//elemento[2]->setEscalado(1 / sqrtf(2.0), 1 / sqrtf(2.0), 1.0);
	elemento[1]->setPosicion(0.0, 0.0, 0.5);
}

void Rueda::setColor(GLfloat red, GLfloat green, GLfloat blue){
	for (int i = 0; i<numeroElementos; i++) {
		elemento[i]->setColor(red, green, blue);
	}
}