 
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


PuntoVector3D* Malla::CalculoVectorNormalPorNewell(Cara* c){
	PuntoVector3D* n = new PuntoVector3D(0, 0, 0, 1);

	for (int i = 0; i < c->getNumeroVertices(); i++){
		PuntoVector3D* vertActual = vertice[c->getIndiceVerticeK(i)];
		PuntoVector3D* vertSiguiente = vertice[c->getIndiceVerticeK((i + 1) % c->getNumeroVertices())];

		n->setX((vertActual->getY() - vertSiguiente->getY()) * (vertActual->getZ() + vertSiguiente->getZ()));

		n->setY((vertActual->getZ() - vertSiguiente->getZ()) * (vertActual->getX() + vertSiguiente->getX()));

		n->setZ((vertActual->getX() - vertSiguiente->getX()) * (vertActual->getY() + vertSiguiente->getY()));

	}

	n->normalizar();

	return n;
}

 

