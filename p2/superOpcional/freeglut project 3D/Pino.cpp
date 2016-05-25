#include "Pino.h"

Pino::Pino() {
	//trash
	int divs = 40;
	float ratioTronco = .7f;
	GLfloat alturaTronco = 4.0f;
	GLfloat alturaCopa = 5.0f;
	GLfloat anchuraCopa = 3.0f;

	numHijos = 6;
	hijos = new Objeto3D*[numHijos];

	hijos[0] = new Cilindro(ratioTronco, divs, divs);
	hijos[0]->setEscala(1.0f, 1.0f, alturaTronco + 1.0f);
	hijos[0]->setRota(-90.0, 0.0, 0.0);
	hijos[0]->setColor(.4f, .0f, .0f);

	hijos[1] = new Disco(0, divs, divs);
	hijos[1]->setRota(90.0, 0.0, 0.0);
	hijos[1]->setColor(.4f, .0f, .0f);

	hijos[2] = new Cilindro(0.0, divs, divs);
	hijos[2]->setTraslada(0.0, alturaTronco, 0.0);
	hijos[2]->setEscala(anchuraCopa, anchuraCopa, alturaCopa);
	hijos[2]->setRota(-90.0, 0.0, 0.0);
	hijos[2]->setColor(.4f, 1.0f, .4f);

	hijos[3] = new Disco(0, divs, divs);
	hijos[3]->setTraslada(0.0, alturaTronco, 0.0);
	hijos[3]->setEscala(anchuraCopa, anchuraCopa, alturaCopa);
	hijos[3]->setRota(90.0, 0.0, 0.0);
	hijos[3]->setColor(.4f, 1.0f, .4f);

	hijos[4] = new Cilindro(0.0, divs, divs);
	hijos[4]->setTraslada(0.0, alturaTronco + alturaCopa - 2, 0.0);
	hijos[4]->setEscala(anchuraCopa, anchuraCopa, alturaCopa);
	hijos[4]->setRota(-90.0, 0.0, 0.0);
	hijos[4]->setColor(.4f, 1.0f, .4f);

	hijos[5] = new Disco(0, divs, divs);
	hijos[5]->setTraslada(0.0, alturaTronco + alturaCopa - 2, 0.0);
	hijos[5]->setEscala(anchuraCopa, anchuraCopa, alturaCopa);
	hijos[5]->setRota(90.0, 0.0, 0.0);
	hijos[5]->setColor(.4f, 1.0f, .4f);

	_2d = new Simple2D(new PuntoVector3D(0.0f, 0.0f, 0.0f, 1), 1.0f);
}

void Pino::setTraslada(GLfloat x, GLfloat y, GLfloat z){
	_2d = new Simple2D(new PuntoVector3D(x, y, z, 1), 1.0f);
	mT->setTraslada(x, y, z);
}

void Pino::setEscala(GLfloat x, GLfloat y, GLfloat z){
	float max = x;
	if (z > max) max = z;
	GLfloat xx = mT->getTraslada()[0];
	GLfloat yy = mT->getTraslada()[1];
	GLfloat zz = mT->getTraslada()[2];
	_2d = new Simple2D(new PuntoVector3D(xx, yy, zz, 1), max);
	mT->setEscala(x, y, z);
}