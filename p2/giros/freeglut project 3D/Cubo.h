#ifndef Cubo_H_
#define Cubo_H_

#include "Conjunto.h"
#include "Cilindro.h"
#include "Disco.h"
#include <math.h>

class Cubo : public Conjunto {
public:
	Cubo();
	void setColor(GLfloat red, GLfloat green, GLfloat blue);
};
#endif