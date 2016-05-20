#ifndef ObjetoCompuesto_H_
#define ObjetoCompuesto_H_

#include "Objeto3D.h"

class ObjetoCompuesto : public Objeto3D {
public:
	ObjetoCompuesto();
	~ObjetoCompuesto();
	void dibuja();
	void _dibuja();

protected:
	int numHijos;
	Objeto3D** hijos;
};
#endif