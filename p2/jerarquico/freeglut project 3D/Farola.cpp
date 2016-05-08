#include "Farola.h"

Farola::Farola() {
	int divs = 40;
	float ratioTronco = 0.7f;
	GLfloat alturaTronco = 6.0f;
	GLfloat anchuraCopa = 2.5f;

	numHijos = 4;
	hijos = new Objeto3D*[numHijos];

	hijos[0] = new Cilindro(ratioTronco, divs, divs);
	hijos[0]->mT->setEscala(1.0, 1.0f, alturaTronco + 1.0f);
	hijos[0]->mT->setRota(-90.0, 0.0, 0.0);

	hijos[1] = new Disco(0, divs, divs);
	hijos[1]->mT->setRota(90.0, 0.0, 0.0);

	hijos[2] = new Esfera(divs, divs);
	hijos[2]->mT->setTraslada(0.0, alturaTronco, 0.0);
	hijos[2]->mT->setEscala(anchuraCopa, anchuraCopa, anchuraCopa);
	hijos[2]->setColor(1.0f, 1.0f, 1.0f);
	
	hijos[3] = new Luz(GL_LIGHT5);
	hijos[3]->mT->setTraslada(0.0, alturaTronco, 0.0);
	dynamic_cast<Luz*>(hijos[3])->setDif(1.0f, 0.0f, 1.0f);
	dynamic_cast<Luz*>(hijos[3])->setEsp(1.0f, 0.0f, 1.0f);
}

void Farola::lightOn(){
	dynamic_cast<Luz*>(hijos[3])->encender();
}

void Farola::lightOff(){
	dynamic_cast<Luz*>(hijos[3])->apagar();
}