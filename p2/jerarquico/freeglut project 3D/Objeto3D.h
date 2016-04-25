#ifndef Objeto3D_H_
#define Objeto3D_H_

#include "PuntoVector3D.h"
#include "Cara.h"
#include "TAfin.h"

class Objeto3D {
public:
	TAfin* mT;
	GLfloat* color;
	Objeto3D();
	~Objeto3D();
	virtual void dibuja();
	virtual void setColor(GLfloat red, GLfloat green, GLfloat blue);
};
#endif
