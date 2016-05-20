#ifndef TAfin_H_
#define TAfin_H_

#include "PuntoVector3D.h"

class TAfin {
private:
	void postmultiplica(GLfloat* m1);
	GLfloat* posicion;
	GLfloat* rotacion;
	GLfloat* escalado;
	void TAfin::applyTransforms();

public:
	GLfloat m[16];
	TAfin();

	void traslada(PuntoVector3D* v);
	void TAfin::rota(GLfloat angulo, PuntoVector3D* v);
	void escala(PuntoVector3D* v);

	void setTraslada(GLfloat x, GLfloat y, GLfloat z);
	void setRota(GLfloat x, GLfloat y, GLfloat z);
	void setEscala(GLfloat x, GLfloat y, GLfloat z);
};
#endif