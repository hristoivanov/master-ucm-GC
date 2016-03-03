#include "Iman.h"
#include <math.h>
#include <iostream>

Iman::Iman() {
	int m = 5;
	PuntoVector3D** perfil = new PuntoVector3D*[m];
	perfil[0] = new PuntoVector3D(3.0f, 0.0f, 0.0f, 1);
	perfil[1] = new PuntoVector3D(6.0f, 0.0f, 0.0f, 1);
	perfil[2] = new PuntoVector3D(6.0f, 3.0f, 0.0f, 1);
	perfil[3] = new PuntoVector3D(3.0f, 3.0f, 0.0f, 1);
	perfil[4] = new PuntoVector3D(3.0f, 0.0f, 0.0f, 1);

	int n = 20;

	//Tamaños de los arrays
	numeroVertices = n*m;
	numeroCaras = n*(m - 1);
	numeroNormales = numeroCaras;

	//Creación de los arrays
	vertice = new PuntoVector3D*[numeroVertices];
	normal = new PuntoVector3D*[numeroNormales];
	cara = new Cara*[numeroCaras];

	//Colocar el perfil original en la tabla de vertices
	for (int j = 0; j<m; j++) vertice[j] = perfil[j]->clonar();

	//Vertices de la malla
	for (int i = 1; i<n; i++){ //generar el perfil i-ésimo
		double theta = i * 180 / (double)n;
		double c = cos(theta*3.14/180.0); 
		double s = sin(theta*3.14/180.0);
		//R_y es la matriz de rotación sobre el eje Y
		for (int j = 0; j<m; j++) {
			int indice = i*m + j;
			//Transformar el punto j-ésimo del perfil original
			double x = c*perfil[j]->getX() + s*perfil[j]->getZ();
			double z = -s*perfil[j]->getX() + c*perfil[j]->getZ();
			PuntoVector3D* p = new PuntoVector3D(x, perfil[j]->getY(), z, 1);
			//std::cout << x << "," << perfil[j]->getY() << ","<< z << "\n";
			vertice[indice] = p;
		} //for
	} //for


	int indiceCara = 0;
	for (int i = 0; i<n; i++){ //unir el perfil i-ésimo con el (i+1)%n-ésimo
		for (int j = 0; j<m - 1; j++) { //esquina inferior-izquierda de una cara
			// indiceCara = i*(m-1) + j;
			int indice = i*m + j;
			VerticeNormal** vn = new VerticeNormal*[4];
			vn[0] = new VerticeNormal(indice, indiceCara);
			vn[1] = new VerticeNormal((indice + m) % numeroVertices, indiceCara);
			vn[2] = new VerticeNormal((indice + 1 + m) % numeroVertices, indiceCara);
			vn[3] = new VerticeNormal(indice + 1, indiceCara);
			//std::cout << indice << "," << (indice + m) % numVertices << "," << (indice + 1 + m) % numVertices << "," << indice + 1 << "\n";
			cara[indiceCara] = new Cara(4, vn);

			PuntoVector3D* v = CalculoVectorNormalPorNewell(cara[indiceCara]); //Newell
			normal[indiceCara] = v;
			indiceCara++;
		} //for
	} //for
	
}




Iman::~Iman() {
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

void Iman::dibuja() {
	for (int i = 0; i<numeroCaras; i++) {
		glBegin(GL_POLYGON);
		glColor3f(0.0f, 1.0f, 0.0f);
		for (int j = 0; j<cara[i]->getNumeroVertices(); j++) {
			std::cout << "Cara = "<< j;
			int iN = cara[i]->getIndiceNormalK(j);
			int iV = cara[i]->getIndiceVerticeK(j);
			glNormal3f(normal[iN]->getX(), normal[iN]->getY(), normal[iN]->getZ());
			glVertex3f(vertice[iV]->getX(), vertice[iV]->getY(), vertice[iV]->getZ());
			std::cout << vertice[iV]->getX() << "," << vertice[iV]->getY() << "," << vertice[iV]->getZ() << "\n";
		}
		glEnd();
	}
}


