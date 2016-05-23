#include "Coche.h"

Coche::Coche() {
	yGiroRuedas = 0.0f;
	zGiroRuedas = 0.0f;
	numHijos = 9;
	hijos = new Objeto3D*[numHijos];

	hijos[0] = new Cubo();
	hijos[0]->setEscala(.3f, .3f, .3f);
	hijos[0]->setColor(1.0f, .0f, 1.0f);

	hijos[1] = new Rueda();
	hijos[1]->setTraslada(1.5, -1.5, 1.5);

	hijos[2] = new Rueda();
	hijos[2]->setTraslada(-1.5, -1.5, 1.5);

	hijos[3] = new Rueda();
	hijos[3]->setTraslada(-1.5, -1.5, -1.5);
	hijos[3]->setRota(0.0, 180.0, 0.0);

	hijos[4] = new Rueda();
	hijos[4]->setTraslada(1.5, -1.5, -1.5);
	hijos[4]->setRota(0.0, 180.0, 0.0);

	hijos[5] = new Cilindro(1.7, 10, 10);
	hijos[5]->setTraslada(1.5, 0.0, -0.5);
	hijos[5]->setEscala(.2f, .2f, 1.0f);
	hijos[5]->setRota(0.0, 90, 0.0);
	hijos[5]->setColor(.0f, 1.0f, .0f);

	hijos[6] = new Cilindro(1.7, 10, 10);
	hijos[6]->setTraslada(1.5, 0.0, 0.5);
	hijos[6]->setEscala(.2f, .2f, 1.0f);
	hijos[6]->setRota(0.0, 90, 0.0);
	hijos[6]->setColor(.0f, 1.0f, .0f);

	hijos[7] = new Faro(GL_LIGHT6);
	hijos[7]->setTraslada(1.5, 0.0, -0.5);
	hijos[7]->setRota(0.0, -90, 0.0);
	dynamic_cast<Faro*>(hijos[7])->setAng(10.0f);
	dynamic_cast<Faro*>(hijos[7])->setAmb(1.0f, 1.0f, 0.0f);
	dynamic_cast<Faro*>(hijos[7])->setDif(1.0f, 1.0f, 0.0f);
	dynamic_cast<Faro*>(hijos[7])->setEsp(0.0f, 0.0f, 0.0f);

	hijos[8] = new Faro(GL_LIGHT7);
	hijos[8]->setTraslada(1.5, 0.0, 0.5);
	hijos[8]->setRota(0.0, -90, 0.0);
	dynamic_cast<Faro*>(hijos[8])->setAng(10.0f);
	dynamic_cast<Faro*>(hijos[8])->setAmb(1.0f, 1.0f, 0.0f);
	dynamic_cast<Faro*>(hijos[8])->setDif(1.0f, 1.0f, 0.0f);
	dynamic_cast<Faro*>(hijos[8])->setEsp(0.0f, 0.0f, 0.0f);
}

void Coche::avanza(GLfloat f){
	this->traslada(new PuntoVector3D(f, 0.0f, 0.0f, 0));
	
	zGiroRuedas += -(f / 3.14f) * 180.0f;

	hijos[1]->setRota(0.0f, 0.0f, zGiroRuedas);
	hijos[2]->setRota(0.0f, 0.0f, zGiroRuedas);
	hijos[3]->setRota(0.0f, 180.0f, -zGiroRuedas);
	hijos[4]->setRota(0.0f, 180.0f, -zGiroRuedas);
}

void Coche::avanzaGiro(GLfloat f, GLfloat turn){
	PuntoVector3D* yAxis = new PuntoVector3D(0.0f, 1.0f, 0.0f, 0);

	this->rota(turn, yAxis);
	this->traslada(new PuntoVector3D(f, 0.0f, 0.0f, 0));

	if (f > 0.0f){
		yGiroRuedas = 20.7f * turn;
	}else{
		yGiroRuedas = -20.7f * turn;
	}
	zGiroRuedas += -(f / 3.14f) * 180.0f;

	hijos[1]->setRota(0.0f, yGiroRuedas, zGiroRuedas);
	hijos[2]->setRota(0.0f, 0.0f, zGiroRuedas);
	hijos[3]->setRota(0.0f, 180.0f, -zGiroRuedas);
	hijos[4]->setRota(0.0f, 180.0f + yGiroRuedas, -zGiroRuedas);

	delete(yAxis);
}

void Coche::resetRuedas(GLfloat turn){
	hijos[1]->setRota(0.0f, 0.0f, zGiroRuedas);
	hijos[4]->setRota(0.0f, 180.0f, -zGiroRuedas);
}

void Coche::lightOn(){
	dynamic_cast<Faro*>(hijos[7])->encender();
	dynamic_cast<Faro*>(hijos[8])->encender();
}

void Coche::lightOff(){
	dynamic_cast<Faro*>(hijos[7])->apagar();
	dynamic_cast<Faro*>(hijos[8])->apagar();
}