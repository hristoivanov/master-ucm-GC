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
	hijos[0]->setEscala(1.0f, 1.0f, alturaTronco + 1.0f);
	hijos[0]->setRota(-90.0f, 0.0f, 0.0f);
	hijos[0]->setColor(.4f, .0f, .0f);

	hijos[1] = new Disco(0, divs, divs);
	hijos[1]->setRota(90.0f, 0.0f, 0.0f);
	hijos[1]->setColor(.4f, .0f, .0f);
	
	hijos[2] = new Cilindro(0.0f, divs, divs);
	hijos[2]->setTraslada(0.0f, alturaTronco, 0.0);
	hijos[2]->setEscala(anchuraCopa, anchuraCopa, alturaCopa);
	hijos[2]->setRota(-90.0f, 0.0f, 0.0f);
	hijos[2]->setColor(.4f, 1.0f, .4f);
	
	hijos[3] = new Disco(0, divs, divs);
	hijos[3]->setTraslada(0.0f, alturaTronco, 0.0f);
	hijos[3]->setEscala(anchuraCopa, anchuraCopa, alturaCopa);
	hijos[3]->setRota(90.0f, 0.0f, 0.0f);
	hijos[3]->setColor(.4f, 1.0f, .4f);

	_2d = new Simple2D(new PuntoVector3D(0.0f, 0.0f, 0.0f, 1), 1.0f);
}

void Abeto::setTraslada(GLfloat x, GLfloat y, GLfloat z){
	_2d = new Simple2D(new PuntoVector3D(x, y, z, 1), 1.0f);
	mT->setTraslada(x, y, z);
}

void Abeto::setEscala(GLfloat x, GLfloat y, GLfloat z){
	float max = x;
	if (y > max) max = y;
	if (z > max) max = z;
	_2d = new Simple2D(new PuntoVector3D(x, y, z, 1), max);
	mT->setEscala(x, y, z);
}