#ifndef Cilindro_H_
#define Cilindro_H_

#include "Elemento.h"

class Cilindro : public Elemento {
private:
	GLdouble topRadio;
	GLUquadric* cilindro;
	GLint slices;
	GLint stacks;
public:
	Cilindro(GLdouble topRadio, GLint slices, GLint stacks);
	void dibuja();
};
#endif