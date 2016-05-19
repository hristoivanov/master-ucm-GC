#ifndef Rueda_H_
#define Rueda_H_

#include "ObjetoCompuesto.h"
#include "Cilindro.h"
#include "Disco.h"
#include <math.h>

class Rueda : public ObjetoCompuesto {
public:
	Rueda();
	void setColor(GLfloat red, GLfloat green, GLfloat blue);
};
#endif