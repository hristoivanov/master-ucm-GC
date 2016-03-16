#include "Coche.h"

Coche::Coche() {
	//trash

	numeroElementos = 1;
	elemento = new Elemento*[numeroElementos];

	elemento[0] = new Cilindro(4, 1.0);
	elemento[0]->setRotacion(0.0, 45.0, 0.0);
	elemento[0]->setEscalado(1.44, 1.0, 1.44);
	elemento[0]->setColor(.8, .1, .1);
}