#include "Roble.h"

Roble::Roble() {
	//trash
	int divs = 40;
	float ratioTronco = 0.7f;
	GLfloat alturaTronco = 6.0f;
	GLfloat anchuraCopa = 2.5f;

	numHijos = 3;
	hijos = new Objeto3D*[numHijos];

	hijos[0] = new Cilindro(ratioTronco, divs, divs);
	hijos[0]->setEscala(1.0, 1.0f, alturaTronco + 1.0f);
	hijos[0]->setRota(-90.0, 0.0, 0.0);
	hijos[0]->setColor(.4f, .0f, .0f);

	hijos[1] = new Disco(0, divs, divs);
	hijos[1]->setRota(90.0, 0.0, 0.0);
	hijos[1]->setColor(.4f, .0f, .0f);

	hijos[2] = new Esfera(divs, divs);
	hijos[2]->setTraslada(0.0, alturaTronco, 0.0);
	hijos[2]->setEscala(anchuraCopa, anchuraCopa, anchuraCopa);
	hijos[2]->setColor(.4f, 1.0f, .4f);
	colorEsp = new float[3]();
	colorEsp[0] = .5f; colorEsp[1] = .5f; colorEsp[2] = 0.5f;
}

void Roble::dibuja() {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glMultMatrixf(this->mT->m);
	for (int i = 0; i < numHijos; i++){
		if (i != 2)
			hijos[i]->dibuja();
		else{
			glMaterialfv(GL_FRONT, GL_SPECULAR, colorEsp);
			hijos[i]->dibuja();
			GLfloat amb[] = { 0.0f, 0.0f, 0.0f};
			glMaterialfv(GL_FRONT, GL_SPECULAR, amb);
		}
	}
	glPopMatrix();
}
void Roble::cambiaEsp(float aux) {
	GLfloat a = colorEsp[0] + aux;
	if (a > 1.0f)
		a = 1.0f;
	if (a < .0f)
		a = .0f;

	colorEsp[0] = a;
	colorEsp[1] = a;
	colorEsp[2] = a;
}