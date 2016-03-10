
#ifndef Extrusion_H_
#define Extrusion_H_

#include "Malla.h"

class Extrusion : public Malla {
public:
	Extrusion(int nP, int nQ);
	~Extrusion();
	void dibuja();

private:
	float a = 7;
	float b = 4;
	float c = 2;
	PuntoVector3D* Extrusion::vectC(double t);
	PuntoVector3D* Extrusion::vectT(double t);
	PuntoVector3D* Extrusion::vectB(double t);
	PuntoVector3D* Extrusion::vectN(PuntoVector3D* T, PuntoVector3D* B);
};
#endif