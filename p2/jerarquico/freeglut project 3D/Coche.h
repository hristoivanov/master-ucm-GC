#ifndef Coche_H_
#define Coche_H_

#include "ObjetoCompuesto.h"
#include "Cubo.h"
#include "Rueda.h"

class Coche : public ObjetoCompuesto {
private:
	GLfloat zGiroRuedas;
	GLfloat yGiroRuedas;

public:
	Coche();
	void avanza(GLfloat f);
	void avanzaGiro(GLfloat f, GLfloat turn);
	void resetRuedas(GLfloat turn);
};
#endif