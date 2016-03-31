#include "Iman.h"

Iman::Iman(GLfloat coorX,GLfloat coorY,GLfloat coorZ,GLfloat tamanho) {
	numCubos = 4;
	cubos = new Cubo*[numCubos]; 

	//Revolucion
	rev = new Revolucion(coorX,coorY,coorZ,tamanho);
	//Cubos
	cubos[0] = new Cubo(coorX			,coorY	,coorZ			,tamanho,0.0f		, 0.0f		, 1.0f		);
	cubos[1] = new Cubo(coorX			,coorY	,coorZ+tamanho	,tamanho,0.752941f	, 0.752941f	, 0.752941f	);
	cubos[2] = new Cubo(-coorX-tamanho	,coorY	,coorZ			,tamanho,1.0f		, 0.0f		, 0.0f		);
	cubos[3] = new Cubo(-coorX-tamanho	,coorY	,coorZ+tamanho	,tamanho,0.752941f	, 0.752941f	, 0.752941f	);
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

