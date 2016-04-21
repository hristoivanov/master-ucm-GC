
#ifndef Extrusion_H_
#define Extrusion_H_

#include "Malla.h"

class Extrusion : public Malla {
public:
	Extrusion(int nP, int nQ);
	~Extrusion();
	void dibuja();
	void CambiaEstilo(GLenum type);
	PuntoVector3D* Extrusion::getPositionCamara(GLfloat t);

private:
	GLenum type;
	float a;
	float b;
	float c;
	PuntoVector3D* Extrusion::vectC(GLfloat t);
	PuntoVector3D* Extrusion::vectT(GLfloat t);
	PuntoVector3D* Extrusion::vectB(GLfloat t);
	PuntoVector3D* Extrusion::vectN(PuntoVector3D* T, PuntoVector3D* B);
};
#endif