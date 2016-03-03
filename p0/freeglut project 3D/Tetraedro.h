
#ifndef Tetraedro_H_
#define Tetraedro_H_

#include "Malla.h"

//#include "Prueba.h"

class Tetraedro : public Malla {
private:
	GLenum type;
public:
	Tetraedro();
	~Tetraedro();
	void dibuja();
	void CambiaEstilo();
};
#endif