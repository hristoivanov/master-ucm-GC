#include "Abeto.h"

Abeto::Abeto() {
	//trash
	int divs = 40;
	float ratioTronco = .7f;
	GLfloat alturaTronco = 4.0f;
	GLfloat alturaCopa = 5.0f;
	GLfloat anchuraCopa = 3.0f;

	numHijos = 4;
	hijos = new Objeto3D*[numHijos];

	hijos[0] = new Cilindro(ratioTronco, divs, divs);
	hijos[0]->mT->setEscala(1.0f, 1.0f, alturaTronco + 1.0f);
	hijos[0]->mT->setRota(-90.0f, 0.0f, 0.0f);
	hijos[0]->setColor(.4f, .0f, .0f);

	hijos[1] = new Disco(0, divs, divs);
	hijos[1]->mT->setRota(90.0f, 0.0f, 0.0f);
	hijos[1]->setColor(.4f, .0f, .0f);
	
	hijos[2] = new Cilindro(0.0f, divs, divs);
	hijos[2]->mT->setTraslada(0.0f, alturaTronco, 0.0);
	hijos[2]->mT->setEscala(anchuraCopa, anchuraCopa, alturaCopa);
	hijos[2]->mT->setRota(-90.0f, 0.0f, 0.0f);
	hijos[2]->setColor(.4f, 1.0f, .4f);
	
	hijos[3] = new Disco(0, divs, divs);
	hijos[3]->mT->setTraslada(0.0f, alturaTronco, 0.0f);
	hijos[3]->mT->setEscala(anchuraCopa, anchuraCopa, alturaCopa);
	hijos[3]->mT->setRota(90.0f, 0.0f, 0.0f);
	hijos[3]->setColor(.4f, 1.0f, .4f);
}