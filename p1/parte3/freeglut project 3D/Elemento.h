#ifndef Elemento_H_
#define Elemento_H_

#include "PuntoVector3D.h"
#include "Cara.h"
#include "Color.h"

class Elemento {
protected:
	int numeroVertices;
	PuntoVector3D** vertice;
	int numeroNormales;
	PuntoVector3D** normal;
	int numeroCaras;
	Cara** cara;
	int numeroColores;
	Color** color;

	PuntoVector3D* posicion;
	PuntoVector3D* rotacion;
	PuntoVector3D* escalado;

public:
	Elemento();
	~Elemento();
	int getNumeroVertices();
	int getNumeroNormales();
	int getNumeroCaras();
	virtual void dibuja();
	PuntoVector3D* CalculoVectorNormalPorNewell(Cara* c);
};
#endif
