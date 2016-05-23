#ifndef Camara2D_H
#define Camara2D_H

#include "PuntoVector3D.h"
#include "Simple2D.h"
#include "TAfin.h"

#include <iostream>
using namespace std;

class Camara2D {
private:
	PuntoVector3D *eye, *up, *look, *u, *v, *n;
	GLfloat left, right, bottom, top, Near, Far;
	GLfloat fovy, aspect;

	PuntoVector3D* incForward;

	void setView();
	void setCameraCoordinateSystem();

public:
	Camara2D();
	void setModelViewMatrix();
	void setProjection();

	void moveForward();
	void rotate(float ang);

	Simple2D* get2D();
};
#endif
