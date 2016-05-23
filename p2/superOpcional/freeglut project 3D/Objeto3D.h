#ifndef Objeto3D_H_
#define Objeto3D_H_

#include "PuntoVector3D.h"
#include "Cara.h"
#include "TAfin.h"
#include "Simple2D.h"

class Objeto3D {
protected:
	TAfin* mT;

public:
	GLfloat* color;

	Objeto3D();
	~Objeto3D();
	virtual void dibuja();
	virtual void _dibuja();
	virtual void setColor(GLfloat red, GLfloat green, GLfloat blue);

	virtual void traslada(PuntoVector3D* v);
	virtual void rota(GLfloat angulo, PuntoVector3D* v);
	virtual void escala(PuntoVector3D* v);

	virtual void setTraslada(GLfloat x, GLfloat y, GLfloat z);
	virtual void setRota(GLfloat x, GLfloat y, GLfloat z);
	virtual void setEscala(GLfloat x, GLfloat y, GLfloat z);

	GLfloat* getTraslada();
	GLfloat* getRota();
	GLfloat* getEscala();

	Simple2D* _2d;
};
#endif
