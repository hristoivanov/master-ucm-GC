#ifndef Pino_H_
#define Pino_H_

#include "ObjetoCompuesto.h"
#include "Cilindro.h"
#include "Disco.h"

class Pino : public ObjetoCompuesto {
public:
	Pino();
	void setTraslada(GLfloat x, GLfloat y, GLfloat z);
	void setEscala(GLfloat x, GLfloat y, GLfloat z);
};
#endif