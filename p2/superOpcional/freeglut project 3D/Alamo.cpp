#include "Alamo.h"

Alamo::Alamo() {
	//trash
	int divs = 40;
	float ratioTronco = .7f;
	GLfloat alturaTronco = 6.0f;
	GLfloat anchuraCopa = 2.5f;

	numHijos = 4;
	hijos = new Objeto3D*[numHijos];

	hijos[0] = new Cilindro(ratioTronco, divs, divs);
	hijos[0]->setEscala(1.0f, 1.0f, alturaTronco + 1.0f);
	hijos[0]->setRota(-90.0f, 0.0f, 0.0f);
	hijos[0]->setColor(.4f, .0f, .0f);

	hijos[1] = new Disco(0, divs, divs);
	hijos[1]->setRota(90.0, 0.0, 0.0);
	hijos[1]->setColor(.4f, .0f, .0f);

	hijos[2] = new Esfera(divs, divs);
	hijos[2]->setTraslada(-anchuraCopa / 2.0f, alturaTronco, 0.0f);
	hijos[2]->setEscala(anchuraCopa, anchuraCopa, anchuraCopa);
	hijos[2]->setColor(.4f, 1.0f, .4f);

	hijos[3] = new Esfera(divs, divs);
	hijos[3]->setTraslada(anchuraCopa / 2.0f, alturaTronco, 0.0f);
	hijos[3]->setEscala(anchuraCopa, anchuraCopa, anchuraCopa);
	hijos[3]->setColor(.4f, 1.0f, .4f);
}

void Alamo::setTraslada(GLfloat x, GLfloat y, GLfloat z){
	_2d = new Simple2D(new PuntoVector3D(x, y, z, 1), 1.0f);
	mT->setTraslada(x, y, z);
}

void Alamo::setEscala(GLfloat x, GLfloat y, GLfloat z){
	float max = x;
	if (z > max) max = z;
	GLfloat xx = mT->getTraslada()[0];
	GLfloat yy = mT->getTraslada()[1];
	GLfloat zz = mT->getTraslada()[2];
	_2d = new Simple2D(new PuntoVector3D(xx, yy, zz, 1), max);
	mT->setEscala(x, y, z);
}