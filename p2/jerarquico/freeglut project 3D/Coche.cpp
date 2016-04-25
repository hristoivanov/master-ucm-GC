#include "Coche.h"

Coche::Coche() {
	yGiroRuedas = 0.0f;
	zGiroRuedas = 0.0f;
	numHijos = 7;
	hijos = new Objeto3D*[numHijos];

	hijos[0] = new Cubo();
	hijos[0]->mT->setEscala(3, 3, 3);
	hijos[0]->setColor(.6f, .0f, .6f);

	hijos[1] = new Rueda();
	hijos[1]->mT->setTraslada(1.5, -1.5, 1.5);

	hijos[2] = new Rueda();
	hijos[2]->mT->setTraslada(-1.5, -1.5, 1.5);

	hijos[3] = new Rueda();
	hijos[3]->mT->setTraslada(-1.5, -1.5, -1.5);
	hijos[3]->mT->setRota(0.0, 180.0, 0.0);

	hijos[4] = new Rueda();
	hijos[4]->mT->setTraslada(1.5, -1.5, -1.5);
	hijos[4]->mT->setRota(0.0, 180.0, 0.0);

	hijos[5] = new Cilindro(1.7, 10, 10);
	hijos[5]->mT->setTraslada(1.5, 0.0, -0.5);
	hijos[5]->mT->setEscala(.2f, .2f, 1.0f);
	hijos[5]->mT->setRota(0.0, 90, 0.0);
	hijos[5]->setColor(.0f, 1.0f, .0f);

	hijos[6] = new Cilindro(1.7, 10, 10);
	hijos[6]->mT->setTraslada(1.5, 0.0, 0.5);
	hijos[6]->mT->setEscala(.2f, .2f, 1.0f);
	hijos[6]->mT->setRota(0.0, 90, 0.0);
	hijos[6]->setColor(.0f, 1.0f, .0f);
}

void Coche::avanza(GLfloat f){
	this->mT->traslada(new PuntoVector3D(f, 0.0f, 0.0f, 0));
	
	zGiroRuedas += -(f / 3.14f) * 180.0f;

	hijos[1]->mT->setRota(0.0f, 0.0f, zGiroRuedas);
	hijos[2]->mT->setRota(0.0f, 0.0f, zGiroRuedas);
	hijos[3]->mT->setRota(0.0f, 0.0f, zGiroRuedas);
	hijos[4]->mT->setRota(0.0f, 0.0f, zGiroRuedas);
}

void Coche::avanzaGiro(GLfloat f, GLfloat turn){
	PuntoVector3D* yAxis = new PuntoVector3D(0.0f, 1.0f, 0.0f, 0.0f);

	this->mT->rota(turn, yAxis);
	this->mT->traslada(new PuntoVector3D(f, 0.0f, 0.0f, 0));

	if (f > 0.0f){
		yGiroRuedas = 20.7f * turn;
	}else{
		yGiroRuedas = -20.7f * turn;
	}
	zGiroRuedas += -(f / 3.14f) * 180.0f;

	hijos[1]->mT->setRota(0.0f, yGiroRuedas, zGiroRuedas);
	hijos[2]->mT->setRota(0.0f, 0.0f, zGiroRuedas);
	hijos[3]->mT->setRota(0.0f, 0.0f, zGiroRuedas);
	hijos[4]->mT->setRota(0.0f, yGiroRuedas, zGiroRuedas);

	delete(yAxis);
}

void Coche::resetRuedas(GLfloat turn){
	hijos[1]->mT->setRota(0.0f, 0.0f, zGiroRuedas);
	hijos[4]->mT->setRota(0.0f, 0.0f, zGiroRuedas);
}