#ifndef Revolucion_H_
#define Revolucion_H_

#include "Malla.h"

class Revolucion : public Malla {
public:
	Revolucion(GLfloat coorX,GLfloat coorY,GLfloat coorZ,GLfloat tamanho);
	~Revolucion();
	void dibuja();
};
#endif