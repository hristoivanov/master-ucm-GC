
#ifndef Extrusion_H_
#define Extrusion_H_

#include "Malla.h"

class Extrusion : public Malla {
public:
	Extrusion(int nP, int nQ);
	~Extrusion();
	void dibuja();

private:
	float a;
	float b;
	float c;
	PuntoVector3D* Extrusion::vectC(double t);
	PuntoVector3D* Extrusion::vectT(double t);
	PuntoVector3D* Extrusion::vectB(double t);
	PuntoVector3D* Extrusion::vectN(PuntoVector3D* T, PuntoVector3D* B);
};
#endif