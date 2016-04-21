#ifndef Esfera_H_
#define Esfera_H_

#include "Elemento.h"

class Esfera : public Elemento {
private:
	GLint meridianos;
	GLint paralelos;
	GLUquadric* esfera;
public:
	Esfera(GLint meridianos, GLint paralelos);
	void dibuja();
};
#endif