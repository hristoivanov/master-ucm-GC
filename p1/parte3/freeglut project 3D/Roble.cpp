#include "Roble.h"

Roble::Roble() {
	//trash
	int divs = 40;
	float ratioTronco = .7;
	GLfloat alturaTronco = 6.0f;
	GLfloat anchuraCopa = 2.5f;

	numeroElementos = 3;
	elemento = new Elemento*[numeroElementos];

	elemento[0] = new Cilindro(ratioTronco, divs, divs);
	elemento[0]->setEscalado(1.0, 1.0, alturaTronco + 1);
	elemento[0]->setRotacion(-90.0, 0.0, 0.0);
	elemento[0]->setColor(.4, .0, .0);

	elemento[1] = new Disco(0, divs, divs);
	elemento[1]->setRotacion(90.0, 0.0, 0.0);
	elemento[1]->setColor(.4, .0, .0);

	elemento[2] = new Esfera(divs, divs);
	elemento[2]->setEscalado(anchuraCopa, anchuraCopa, anchuraCopa);
	elemento[2]->setPosicion(0.0, alturaTronco, 0.0);
	elemento[2]->setColor(.4, 1, .4);
}