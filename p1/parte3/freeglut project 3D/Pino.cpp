#include "Pino.h"

Pino::Pino() {
	//trash
	int divs = 40;
	float ratioTronco = .7;
	GLfloat alturaTronco = 4.0f;
	GLfloat alturaCopa = 5.0f;
	GLfloat anchuraCopa = 3.0f;

	numeroElementos = 6;
	elemento = new Elemento*[numeroElementos];

	elemento[0] = new Cilindro(ratioTronco, divs, divs);
	elemento[0]->setEscalado(1.0, 1.0, alturaTronco + 1);
	elemento[0]->setRotacion(-90.0, 0.0, 0.0);
	elemento[0]->setColor(.4, .0, .0);

	elemento[1] = new Disco(0, divs, divs);
	elemento[1]->setRotacion(90.0, 0.0, 0.0);
	elemento[1]->setColor(.4, .0, .0);

	elemento[2] = new Cilindro(0.0, divs, divs);
	elemento[2]->setEscalado(anchuraCopa, anchuraCopa, alturaCopa);
	elemento[2]->setRotacion(-90.0, 0.0, 0.0);
	elemento[2]->setPosicion(0.0, alturaTronco, 0.0);
	elemento[2]->setColor(.4, 1, .4);

	elemento[3] = new Disco(0, divs, divs);
	elemento[3]->setEscalado(anchuraCopa, anchuraCopa, alturaCopa);
	elemento[3]->setRotacion(90.0, 0.0, 0.0);
	elemento[3]->setPosicion(0.0, alturaTronco, 0.0);
	elemento[3]->setColor(.4, 1, .4);

	elemento[4] = new Cilindro(0.0, divs, divs);
	elemento[4]->setEscalado(anchuraCopa, anchuraCopa, alturaCopa);
	elemento[4]->setRotacion(-90.0, 0.0, 0.0);
	elemento[4]->setPosicion(0.0, alturaTronco + alturaCopa - 2, 0.0);
	elemento[4]->setColor(.4, 1, .4);

	elemento[5] = new Disco(0, divs, divs);
	elemento[5]->setEscalado(anchuraCopa, anchuraCopa, alturaCopa);
	elemento[5]->setRotacion(90.0, 0.0, 0.0);
	elemento[5]->setPosicion(0.0, alturaTronco + alturaCopa-2, 0.0);
	elemento[5]->setColor(.4, 1, .4);
}