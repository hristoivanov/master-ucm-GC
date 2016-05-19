#include "ObjetoCompuesto.h"
 
ObjetoCompuesto::ObjetoCompuesto() {}

ObjetoCompuesto::~ObjetoCompuesto() {
	for (int i=0; i<numHijos; i++)
		delete hijos[i];
	delete[] hijos;
}

void ObjetoCompuesto::dibuja() {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glMultMatrixf(this->mT->m);
		for (int i = 0; i<numHijos; i++)
			hijos[i]->dibuja();
	glPopMatrix();
}

void ObjetoCompuesto::_dibuja() {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glMultMatrixf(this->mT->m);
		for (int i = 0; i<numHijos; i++)
			hijos[i]->_dibuja();
	glPopMatrix();
}