#include "Revolucion.h"
#include <math.h>
#include <iostream>

Revolucion::Revolucion(int nQ, GLfloat rInt, GLfloat rExt) {
	int m = 4;
	PuntoVector3D** perfil = new PuntoVector3D*[m];
	perfil[0] = new PuntoVector3D(rInt, 0.0f, 0.0f, 1);
	perfil[1] = new PuntoVector3D(rExt, 0.0f, 0.0f, 1);
	perfil[2] = new PuntoVector3D(rExt, rExt - rInt, 0.0f, 1);
	perfil[3] = new PuntoVector3D(rInt, rExt - rInt, 0.0f, 1);

	//Tama�os de los arrays
	numeroVertices = (1 + nQ)*m;
	numeroCaras = nQ*m;
	numeroNormales = numeroCaras;

	//Creaci�n de los arrays
	vertice = new PuntoVector3D*[numeroVertices];
	normal = new PuntoVector3D*[numeroNormales];
	cara = new Cara*[numeroCaras];

	//Colocar el perfil original en la tabla de vertices
	//for (int j = 0; j<m; j++) vertice[j] = perfil[j]->clonar();

	//Vertices de la malla
	for (int i = 0; i<nQ + 1; i++){ //generar el perfil i-�simo
		GLfloat theta = i * 180.0f / (GLfloat)nQ;
		GLfloat c = cos(theta*3.14f/180.0f);
		GLfloat s = sin(theta*3.14f/180.0f);
		//R_y es la matriz de rotaci�n sobre el eje Y
		for (int j = 0; j<m; j++) {
			int indice = i*m + j;
			//Transformar el punto j-�simo del perfil original
			GLfloat x = c*perfil[j]->getX() + s*perfil[j]->getZ();
			GLfloat z = -s*perfil[j]->getX() + c*perfil[j]->getZ();
			PuntoVector3D* p = new PuntoVector3D(x, perfil[j]->getY(), z, 1);
			vertice[indice] = p;
		} //for
	} //for

	//Construcci�n de las caras
	int indiceCara = 0;
	for (int i = 0; i<nQ; i++){ //unir el perfil i-�simo con el (i+1)%n-�simo
		for (int j = 0; j<m; j++) { //esquina inferior-izquierda de una cara
			// indiceCara = i*(m-1) + j;
			int indice = i*m + j;
			VerticeNormal** vn = new VerticeNormal*[4];
			vn[0] = new VerticeNormal(indice, indiceCara);
			vn[1] = new VerticeNormal((indice + m) % numeroVertices, indiceCara);
			if (j == m - 1){
				vn[2] = new VerticeNormal((indice + 1) % numeroVertices, indiceCara);
				vn[3] = new VerticeNormal(indice - m + 1, indiceCara);
			}else{
				vn[2] = new VerticeNormal((indice + 1 + m) % numeroVertices, indiceCara);
				vn[3] = new VerticeNormal(indice + 1, indiceCara);
			}
			cara[indiceCara] = new Cara(4, vn);

			PuntoVector3D* v = CalculoVectorNormal(cara[indiceCara]); //Newell
			normal[indiceCara] = v;
			indiceCara++;
		} //for
	} //for
}

Revolucion::~Revolucion() {
	for (int i = 0; i<numeroVertices; i++)
		delete vertice[i];
	delete[] vertice;

	for (int i = 0; i<numeroNormales; i++)
		delete normal[i];
	delete[] normal;

	for (int i = 0; i<numeroCaras; i++)
		delete cara[i];
	delete[] cara;
}

void Revolucion::dibuja() {
	glMatrixMode(GL_MODELVIEW);
	glColor3f(0.0f, 0.0f, 1.0f);
	for (int i = 0; i<numeroCaras; i++) {
		if (i * 2 +1> numeroCaras){
			glColor3f(1.0f, 0.0f, 0.0f);
		}
		glBegin(GL_POLYGON);
		for (int j = 0; j<cara[i]->getNumeroVertices(); j++) {
			int iN = cara[i]->getIndiceNormalK(j);
			int iV = cara[i]->getIndiceVerticeK(j);
			glNormal3f(normal[iN]->getX(), normal[iN]->getY(), normal[iN]->getZ());
			glVertex3f(vertice[iV]->getX(), vertice[iV]->getY(), vertice[iV]->getZ());
		}
		glEnd();
	}
}


