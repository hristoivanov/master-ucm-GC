#include "Elemento.h"
 
Elemento::Elemento() {
	color = new float[3]();
	posicion = new float[3]();
	rotacion = new float[3]();
	escalado = new float[3]();
	escalado[0] = 1.0; escalado[1] = 1.0; escalado[2] = 1.0;
}

Elemento::~Elemento() {
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

}
