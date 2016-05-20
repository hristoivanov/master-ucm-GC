#ifndef Esfera_H_
#define Esfera_H_

#include "Objeto3D.h"

class Esfera : public Objeto3D {
private:
	GLint meridianos;
	GLint paralelos;
	GLUquadric* esfera;
public:
	Esfera(GLint meridianos, GLint paralelos);
	void dibuja();
};
#endif