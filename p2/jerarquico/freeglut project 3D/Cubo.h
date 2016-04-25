#ifndef Cubo_H_
#define Cubo_H_

#include "ObjetoCompuesto.h"
#include "Cilindro.h"
#include "Disco.h"
#include <math.h>

class Cubo : public ObjetoCompuesto {
public:
	Cubo();
	void setColor(GLfloat red, GLfloat green, GLfloat blue);
};
#endif