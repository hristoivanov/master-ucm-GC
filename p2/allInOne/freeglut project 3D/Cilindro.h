#ifndef Cilindro_H_
#define Cilindro_H_

#include "Objeto3D.h"

class Cilindro : public Objeto3D {
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