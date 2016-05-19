#ifndef Roble_H_
#define Roble_H_

#include "ObjetoCompuesto.h"
#include "Cilindro.h"
#include "Disco.h"
#include "Esfera.h"

class Roble : public ObjetoCompuesto {
private:
	GLfloat* colorEsp;
public:
	Roble();
	void dibuja();
	void cambiaEsp(float aux);
};
#endif