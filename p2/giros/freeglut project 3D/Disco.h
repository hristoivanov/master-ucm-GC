#ifndef Disco_H_
#define Disco_H_

#include "Elemento.h"

class Disco : public Elemento {
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