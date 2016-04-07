#ifndef Revolucion_H_
#define Revolucion_H_

#include "Malla.h"

class Revolucion : public Malla {
public:
	Revolucion(int nQ, GLfloat rInt,GLfloat rExt);
	~Revolucion();
	void dibuja();
};
#endif