#ifndef Conjunto_H_
#define Conjunto_H_

#include "Elemento.h"

class Conjunto : public Elemento {
public:
	Conjunto();
	~Conjunto();
	virtual void dibuja();

protected:
	int numeroElementos;
	Elemento** elemento;
};
#endif