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

	GLfloat* color;
	GLfloat* posicion;
	GLfloat* rotacion;
	GLfloat* escalado;

public:
	Elemento();
	~Elemento();
	virtual void dibuja();
	void setColor(GLfloat red, GLfloat green, GLfloat blue);
	void setPosicion(GLfloat x, GLfloat y, GLfloat z);
	void setRotacion(GLfloat x, GLfloat y, GLfloat z);
	void setEscalado(GLfloat x, GLfloat y, GLfloat z);
	PuntoVector3D* CalculoVectorNormalPorNewell(Cara* c);
};
#endif
