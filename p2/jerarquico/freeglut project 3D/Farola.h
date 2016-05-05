#ifndef Farola_H_
#define Farola_H_

#include "ObjetoCompuesto.h"
#include "Cilindro.h"
#include "Disco.h"
#include "Esfera.h"
#include "Luz.h"

class Farola : public ObjetoCompuesto {
public:
	Farola();
	void lightOn();
	void lightOff();

};
#endif