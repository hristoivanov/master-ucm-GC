#ifndef Disco_H_
#define Disco_H_

#include "Objeto3D.h"

class Disco : public Objeto3D {
private:
	GLdouble radioInner;
	GLUquadric* disco;
	GLint slices;
	GLint rings;
public:
	Disco(GLdouble radioInner, GLint slices, GLint rings);
	void dibuja();
};
#endif