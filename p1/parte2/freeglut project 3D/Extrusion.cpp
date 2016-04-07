#include "Extrusion.h"
#include <math.h>

Extrusion::Extrusion(int nP, int nQ) {
	type = GL_POLYGON;
	a = 7;
	b = 4;
	c = 2;
	GLfloat radio = .5f;

	PuntoVector3D** perfil = new PuntoVector3D*[nP];
	for (int i = 0; i < nP; i++){
		GLfloat theta = i * 3.14f * 2.0f / (GLfloat)nP;
		GLfloat c = cos(theta);
		GLfloat s = sin(theta);

		perfil[i] = new PuntoVector3D(c*radio, s*radio, 0.0f, 1);
	}

	numeroVertices = nP * nQ;
	numeroCaras = nP * nQ;
	numeroNormales = numeroCaras;

	//Creación de los arrays
	vertice = new PuntoVector3D*[numeroVertices];
	normal = new PuntoVector3D*[numeroNormales];
	cara = new Cara*[numeroCaras];

	for (int i = 0; i < nQ; i++){ //generar el perfil i-ésimo
		GLfloat t = (8.0f * 3.14f * i) / nQ;
		PuntoVector3D* C = vectC(t);
		PuntoVector3D* T = vectT(t);
		PuntoVector3D* B = vectB(t);
		PuntoVector3D* N = vectN(T, B);

		for (int j = 0; j<nP; j++) {
			int indice = i*nP + j;
			//Transformar el punto j-ésimo del perfil original
			GLfloat x = N->getX() * perfil[j]->getX() + B->getX() * perfil[j]->getY() + T->getX() * perfil[j]->getZ() + C->getX();
			GLfloat y = N->getY() * perfil[j]->getX() + B->getY() * perfil[j]->getY() + T->getY() * perfil[j]->getZ() + C->getY();
			GLfloat z = N->getZ() * perfil[j]->getX() + B->getZ() * perfil[j]->getY() + T->getZ() * perfil[j]->getZ() + C->getZ();
			PuntoVector3D* p = new PuntoVector3D(x, y, z, 1);
			vertice[indice] = p;
		} //for
	}

	int indiceCara = 0;
	for (int i = 0; i<nQ; i++){ //unir el perfil i-ésimo con el (i+1)%n-ésimo
		for (int j = 0; j<nP; j++) { //esquina inferior-izquierda de una cara
			// indiceCara = i*(m-1) + j;
			int indice = i*nP + j;
			VerticeNormal** vn = new VerticeNormal*[4];
			vn[0] = new VerticeNormal(indice, indiceCara);
			vn[1] = new VerticeNormal((indice + nP) % numeroVertices, indiceCara);
			if (j == nP - 1){
				vn[2] = new VerticeNormal((indice + 1) % numeroVertices, indiceCara);
				vn[3] = new VerticeNormal(indice - nP + 1, indiceCara);
			}
			else{
				vn[2] = new VerticeNormal((indice + 1 + nP) % numeroVertices, indiceCara);
				vn[3] = new VerticeNormal(indice + 1, indiceCara);
			}
			cara[indiceCara] = new Cara(4, vn);

			PuntoVector3D* v = CalculoVectorNormal(cara[indiceCara]); //Newell
			normal[indiceCara] = v;
			indiceCara++;
		} //for
	} //for
}

PuntoVector3D* Extrusion::vectC(GLfloat t) {
	PuntoVector3D* aux = new PuntoVector3D(
		(a - b) * cos(t) + c * cos(((a - b) / b) * t),
		0.0f,
		(a - b) * sin(t) - c * sin(((a - b) / b) * t),
		0
		);
	return aux;
}

PuntoVector3D* Extrusion::vectT(GLfloat t) {
	PuntoVector3D* aux = new PuntoVector3D(
			-(a - b) * sin(t) - c * sin(((a - b) / b) * t) * ((a - b) / b),
			0.0f,
			(a - b) * cos(t) - c * cos(((a - b) / b) * t) * ((a - b) / b),
			0
		);
	aux->normalizar();
	return aux;
}

PuntoVector3D* Extrusion::vectB(GLfloat t) {
	PuntoVector3D* c1 = new PuntoVector3D(
		-(a - b) * sin(t) - c * sin(((a - b) / b) * t) * ((a - b) / b),
		0.0f,
		(a - b) * cos(t) - c * cos(((a - b) / b) * t) * ((a - b) / b),
		0
		);
	PuntoVector3D* c2 = new PuntoVector3D(
		-(a - b) * cos(t) - c * cos(((a - b) / b) * t) * ((a - b) / b) * ((a - b) / b),
		0.0f,
		-(a - b) * sin(t) + c * sin(((a - b) / b) * t) * ((a - b) / b) * ((a - b) / b),
		0
		);
	PuntoVector3D* aux = c2->productoVectorial(c1);
	aux->normalizar();
	return aux;
}

PuntoVector3D* Extrusion::vectN(PuntoVector3D* T, PuntoVector3D* B){
	return T->productoVectorial(B);
}

Extrusion::~Extrusion() {
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

void Extrusion::dibuja() {
	glMatrixMode(GL_MODELVIEW);
	glColor3f(0.0f, 1.0f, 0.0f);
	for (int i = 0; i<numeroCaras; i++) {
		glBegin(type);
		for (int j = 0; j<cara[i]->getNumeroVertices(); j++) {
			int iN = cara[i]->getIndiceNormalK(j);
			int iV = cara[i]->getIndiceVerticeK(j);
			glNormal3f(normal[iN]->getX(), normal[iN]->getY(), normal[iN]->getZ());
			glVertex3f(vertice[iV]->getX(), vertice[iV]->getY(), vertice[iV]->getZ());
		}
		glEnd();
	}
}

void Extrusion::CambiaEstilo(GLenum type){
	this->type = type;;
}


