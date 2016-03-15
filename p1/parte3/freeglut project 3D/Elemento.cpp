#include "Elemento.h"
 
Elemento::Elemento() {}

Elemento::~Elemento() {
    for (int i=0; i<numeroVertices; i++)
        delete vertice[i];
    delete[] vertice;

    for (int i=0; i<numeroNormales; i++)
        delete normal[i];
    delete[] normal;

    for (int i=0; i<numeroCaras; i++)
        delete cara[i];
    delete[] cara;

    for (int i=0; i<numeroColores; i++)
        delete color[i];
    delete[] color;
}

int Elemento::getNumeroVertices() {
    return numeroVertices;
}

int Elemento::getNumeroNormales() {
    return numeroNormales;
}

int Elemento::getNumeroCaras() {
    return numeroCaras;
}

void Elemento::dibuja() {	 	 
	//glLoadIdentity();
	glPushMatrix();
	glTranslatef(posicion->getX(), posicion->getY(), posicion->getZ());
	glRotatef(posicion->getX(), 1.0f, 0.0f, 0.0f );
	glRotatef(posicion->getY(), 0.0f, 1.0f, 0.0f );
	glRotatef(posicion->getZ(), 0.0f, 0.0f, 1.0f );
	glScalef(escalado->getX(), escalado->getY(), escalado->getZ());

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
	glPopMatrix();
}


PuntoVector3D* Elemento::CalculoVectorNormalPorNewell(Cara* c){
	PuntoVector3D* n = new PuntoVector3D(0, 0, 0, 1);

	for (int i = 0; i < c->getNumeroVertices(); i++){
		PuntoVector3D* vertActual = vertice[c->getIndiceVerticeK(i)];
		PuntoVector3D* vertSiguiente = vertice[c->getIndiceVerticeK((i + 1) % c->getNumeroVertices())];
		int aux = c->getIndiceVerticeK((i + 1) % c->getNumeroVertices());

		n->setX((vertActual->getY() - vertSiguiente->getY()) * (vertActual->getZ() + vertSiguiente->getZ()));

		n->setY((vertActual->getZ() - vertSiguiente->getZ()) * (vertActual->getX() + vertSiguiente->getX()));

		n->setZ((vertActual->getX() - vertSiguiente->getX()) * (vertActual->getY() + vertSiguiente->getY()));

	}

	n->normalizar();

	return n;
}
