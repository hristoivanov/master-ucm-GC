#ifndef Faro_H_
#define Faro_H_

#include "Objeto3D.h"

class Faro : public Objeto3D {
private:
	GLenum lightId;
	GLfloat *dir;
	GLfloat *v;

	GLfloat *amb;
	GLfloat *dif;
	GLfloat *esp;

	GLfloat ang;

public:
	Faro(GLenum lisghtId);
	void dibuja();
	void setAng(GLfloat ang);
	void setAmb(GLfloat r, GLfloat g, GLfloat b);
	void setDif(GLfloat r, GLfloat g, GLfloat b);
	void setEsp(GLfloat r, GLfloat g, GLfloat b);

	void apagar();
	void encender();
};
#endif