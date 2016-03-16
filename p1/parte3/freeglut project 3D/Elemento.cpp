#include "Elemento.h"
 
Elemento::Elemento() {
	color = new float[3]();
	posicion = new float[3]();
	rotacion = new float[3]();
	escalado = new float[3]();
	escalado[0] = 1.0; escalado[1] = 1.0; escalado[2] = 1.0;
}

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

	delete posicion;
	delete rotacion;
	delete escalado;
}

void Elemento::setColor(GLfloat red, GLfloat green, GLfloat blue){
	color[0] = red;
	color[1] = green;
	color[2] = blue;
}

void Elemento::setPosicion(GLfloat x, GLfloat y, GLfloat z){
	posicion[0] = x;
	posicion[1] = y;
	posicion[2] = z;
}

void Elemento::setRotacion(GLfloat x, GLfloat y, GLfloat z){
	rotacion[0] = x;
	rotacion[1] = y;
	rotacion[2] = z;
}

void Elemento::setEscalado(GLfloat x, GLfloat y, GLfloat z){
	escalado[0] = x;
	escalado[1] = y;
	escalado[2] = z;
}

void Elemento::dibuja() {
	glPushMatrix();;
	glTranslatef(posicion[0], posicion[1], posicion[2]);
	glRotatef(rotacion[0], 1.0f, 0.0f, 0.0f );
	glRotatef(rotacion[1], 0.0f, 1.0f, 0.0f );
	glRotatef(rotacion[2], 0.0f, 0.0f, 1.0f );
	glScalef(escalado[0], escalado[1], escalado[2]);

	glColor3f(color[0], color[1], color[2]);
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
