#include "Cilindro.h"

Cilindro::Cilindro(int nP, float ratio) {
	numeroVertices = nP * 2;
	numeroCaras = nP + 2;
	numeroNormales = numeroCaras;

	//Creación de los arrays
	vertice = new PuntoVector3D*[numeroVertices];
	normal = new PuntoVector3D*[numeroNormales];
	cara = new Cara*[numeroCaras];

	float radio = .5;

	for (int i = 0; i < 2; i++){
		for (int j = 0; j < nP; j++){
			float theta = j * 3.14 * 2.0 / (float)nP;
			float c = cos(theta);
			float s = sin(theta);

			if (i==0) vertice[j+(i*nP)] = new PuntoVector3D(c*radio, i, s*radio, 1);
			if (i==1) vertice[j+(i*nP)] = new PuntoVector3D(c*radio*ratio, i, s*radio*ratio, 1);
		}
	}

	int indiceCara = 0;
	for (int j = 0; j < nP; j++){
		VerticeNormal** vn = new VerticeNormal*[4];
		vn[0] = new VerticeNormal(j, indiceCara);
		vn[1] = new VerticeNormal((j + nP) % numeroVertices, indiceCara);
		if (j == nP - 1){
			vn[2] = new VerticeNormal((j + 1) % numeroVertices, indiceCara);
			vn[3] = new VerticeNormal(j - nP + 1, indiceCara);
		}
		else{
			vn[2] = new VerticeNormal((j + 1 + nP) % numeroVertices, indiceCara);
			vn[3] = new VerticeNormal(j + 1, indiceCara);
		}
		cara[indiceCara] = new Cara(4, vn);

		PuntoVector3D* v = CalculoVectorNormalPorNewell(cara[indiceCara]); //Newell
		normal[indiceCara] = v;
		indiceCara++;
	}

	for (int j = 0; j<=1 ; j++){
		VerticeNormal** vn = new VerticeNormal*[nP];
		for (int i = 0; i < nP; i++){
			vn[i] = new VerticeNormal(i+(nP*j), indiceCara);
		}
		cara[indiceCara] = new Cara(nP, vn);
	
		PuntoVector3D* v = CalculoVectorNormalPorNewell(cara[indiceCara]); //Newell
		normal[indiceCara] = v;
		indiceCara++;
	}

}