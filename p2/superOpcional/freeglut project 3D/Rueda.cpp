#include "Rueda.h"

Rueda::Rueda() {
	numHijos = 2;
	hijos = new Objeto3D*[numHijos];

	hijos[0] = new Cilindro(1.0, 8, 8);
	hijos[0]->setTraslada(0.0, 0.0, -0.5);

	hijos[1] = new Disco(0, 8, 8);
	hijos[1]->setTraslada(0.0, 0.0, 0.5);
}

void Rueda::setColor(GLfloat red, GLfloat green, GLfloat blue){
	for (int i = 0; i<numHijos; i++) {
		hijos[i]->setColor(red, green, blue);
	}
}