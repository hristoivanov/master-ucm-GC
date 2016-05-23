#ifndef Abeto_H_
#define Abeto_H_

#include "ObjetoCompuesto.h"
#include "Cilindro.h"
#include "Disco.h"

class Abeto : public ObjetoCompuesto {
public:
	Abeto();
	void setTraslada(GLfloat x, GLfloat y, GLfloat z);
	void setEscala(GLfloat x, GLfloat y, GLfloat z);
};
#endif