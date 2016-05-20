#ifndef _Simple2D_H_
#define _Simple2D_H_

#include <math.h>
#include "PuntoVector3D.h"
#include <GL/freeglut.h>

class Simple2D {
private:
	PuntoVector3D* bl; //bottomLeft
	PuntoVector3D* tr; //topRight
public:
	Simple2D(PuntoVector3D** puntos, int leght);
	Simple2D(PuntoVector3D* center, float radius);
	bool isCollinding(Simple2D* other);
};
#endif