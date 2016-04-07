#include "Iman.h"

Iman::Iman(int nQ, GLfloat rInt, GLfloat rExt) {
	numCubos = 4;
	cubos = new Cubo*[numCubos]; 

	//Revolucion
	rev = new Revolucion(nQ, rInt, rExt);
	//Cubos
	cubos[0] = new Cubo(rInt, 0.0f, 0.0f, rExt - rInt, 0.0f, 0.0f, 1.0f);
	cubos[1] = new Cubo(rInt, 0.0f, rExt - rInt, rExt - rInt, 0.752941f, 0.752941f, 0.752941f);
	cubos[2] = new Cubo(-rExt, 0.0f, 0.0f, rExt - rInt, 1.0f, 0.0f, 0.0f);
	cubos[3] = new Cubo(-rExt, 0.0f, rExt - rInt, rExt - rInt, 0.752941f, 0.752941f, 0.752941f);
}

Iman::~Iman() {
	for (int i = 0; i<numCubos; i++)
		delete cubos[i];
	delete[] cubos;

	delete rev;
}

void Iman::dibuja() {
	rev->dibuja();
	for(int i = 0; i < numCubos; i++){
		cubos[i]->dibuja();
	}
}

