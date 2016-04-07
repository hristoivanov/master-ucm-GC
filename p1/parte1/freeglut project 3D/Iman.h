#ifndef Iman_H_
#define Iman_H_
#include "Cubo.h"
#include "Revolucion.h"

class Iman {
private:
	Cubo** cubos; 
	Revolucion* rev;
	int numCubos;
public:
	Iman(int nQ, GLfloat rInt, GLfloat rExt);
	~Iman();
	void dibuja();
};
#endif