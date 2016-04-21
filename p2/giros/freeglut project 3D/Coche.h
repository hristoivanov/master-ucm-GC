#ifndef Coche_H_
#define Coche_H_

#include "Conjunto.h"
#include "Cubo.h"
#include "Rueda.h"

class Coche : public Conjunto {
public:
	Coche();
	void avanza(GLfloat f);
};
#endif