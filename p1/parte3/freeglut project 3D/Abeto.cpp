#include "Abeto.h"

Abeto::Abeto() {
	//trash
	int divs = 40;
	float ratioTronco = .7;
	GLfloat alturaTronco	= 4.0f;
	GLfloat alturaCopa		= 4.0f;
	GLfloat anchuraCopa		= 3.0f;

	numeroElementos = 2;
	elemento = new Elemento*[numeroElementos];

	elemento[0] = new Cilindro(divs, ratioTronco);
	elemento[0]->setEscalado(1.0, alturaTronco, 1.0);
	elemento[0]->setColor(.8, .1, .1);

	elemento[1] = new Cilindro(divs, 0.0);
	elemento[1]->setPosicion(0.0, alturaTronco, 0.0);
	elemento[1]->setEscalado(anchuraCopa, alturaCopa, anchuraCopa);
	elemento[1]->setColor(.0, .9, .1);
}