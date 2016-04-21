#ifndef Rueda_H_
#define Rueda_H_

#include "Conjunto.h"
#include "Cilindro.h"
#include "Disco.h"
#include <math.h>

class Rueda : public Conjunto {
public:
	Rueda();
	void setColor(GLfloat red, GLfloat green, GLfloat blue);
};
#endif