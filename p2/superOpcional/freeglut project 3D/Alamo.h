#ifndef Alamo_H_
#define Alamo_H_

#include "ObjetoCompuesto.h"
#include "Cilindro.h"
#include "Disco.h"
#include "Esfera.h"

class Alamo : public ObjetoCompuesto {
public:
	Alamo();
	void setTraslada(GLfloat x, GLfloat y, GLfloat z);
	void setEscala(GLfloat x, GLfloat y, GLfloat z);
};
#endif