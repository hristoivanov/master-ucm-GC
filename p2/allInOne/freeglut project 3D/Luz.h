#ifndef Luz_H_
#define Luz_H_

#include "Objeto3D.h"

class Luz : public Objeto3D {
private:
	GLenum lightId;
	GLfloat *v;

	GLfloat *amb;
	GLfloat *dif;
	GLfloat *esp;

public:
	Luz(GLenum lisghtId);
	void _dibuja();
	void setAmb(GLfloat r, GLfloat g, GLfloat b);
	void setDif(GLfloat r, GLfloat g, GLfloat b);
	void setEsp(GLfloat r, GLfloat g, GLfloat b);

	void apagar();
	void encender();
};
#endif