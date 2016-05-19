#ifndef Elemento_H_
#define Elemento_H_

#include <GL/freeglut.h>

class Elemento {
public:
	GLfloat* color;
	GLfloat* posicion;
	GLfloat* rotacion;
	GLfloat* escalado;

	Elemento();
	~Elemento();
	virtual void dibuja();
	virtual void setColor(GLfloat red, GLfloat green, GLfloat blue);
	void setPosicion(GLfloat x, GLfloat y, GLfloat z);
	void setRotacion(GLfloat x, GLfloat y, GLfloat z);
	void setEscalado(GLfloat x, GLfloat y, GLfloat z);

};
#endif
