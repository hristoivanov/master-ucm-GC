 
#include "Malla.h"
 
Malla::Malla(int nV, int nN, int nC, PuntoVector3D** v, PuntoVector3D** n, Cara** c) {
	numeroVertices=nV;
    vertice=v;
    numeroNormales=nN;
    normal=n;
    numeroCaras=nC;
    cara=c;    
}

Malla::Malla() {}

Malla::~Malla() {
    for (int i=0; i<numeroVertices; i++)
        delete vertice[i];
    delete[] vertice;

    for (int i=0; i<numeroNormales; i++)
        delete normal[i];
    delete[] normal;

    for (int i=0; i<numeroCaras; i++)
        delete cara[i];
    delete[] cara;
}

int Malla::getNumeroVertices() {
    return numeroVertices;
}

int Malla::getNumeroNormales() {
    return numeroNormales;
}

int Malla::getNumeroCaras() {
    return numeroCaras;
}

void Malla::dibuja() {	 	 
	for (int i=0; i<numeroCaras; i++) {		
		glBegin(GL_POLYGON);			 
		for (int j=0; j<cara[i]->getNumeroVertices(); j++) {
			int iN=cara[i]->getIndiceNormalK(j);
			int iV=cara[i]->getIndiceVerticeK(j);
			glNormal3f(normal[iN]->getX(), normal[iN]->getY(), normal[iN]->getZ());            				 
			glVertex3f(vertice[iV]->getX(), vertice[iV]->getY(), vertice[iV]->getZ());
		}
		glEnd();
	}	 
}


PuntoVector3D* Malla::CalculoVectorNormal(Cara* c){
	PuntoVector3D* v1 = vertice[c->getIndiceVerticeK(0)];
	PuntoVector3D* v2 = vertice[c->getIndiceVerticeK(1)];
	PuntoVector3D* v3 = vertice[c->getIndiceVerticeK(2)];
	PuntoVector3D* mult = (new PuntoVector3D(v2->getX() - v1->getX(), v2->getY() - v1->getY(), v2->getZ() - v1->getZ(), 0))->productoVectorial(
		new PuntoVector3D(v3->getX() - v1->getX(), v3->getY() - v1->getY(), v3->getZ() - v1->getZ(), 0));
	mult->normalizar();
	return mult;
}

 

