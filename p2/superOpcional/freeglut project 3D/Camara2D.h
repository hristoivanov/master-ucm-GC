#ifndef Camara2D_H
#define Camara2D_H

#include "PuntoVector3D.h"

class Camara2D {
private:
	PuntoVector3D *eye, *up, *look, *u, *v, *n;
	GLfloat left, right, bottom, top, Near, Far;

	void setView();
	void setCameraCoordinateSystem();

public:
	Camara2D();
	void setModelViewMatrix();

	void moveForward();
	void setProjection();
};
#endif
