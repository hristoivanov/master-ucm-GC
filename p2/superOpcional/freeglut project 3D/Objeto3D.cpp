#include "Objeto3D.h"
 
Objeto3D::Objeto3D(){
	color = new float[3]();
	mT = new TAfin();
}

Objeto3D::~Objeto3D(){
	delete(mT);
}

void Objeto3D::setColor(GLfloat red, GLfloat green, GLfloat blue){
	color[0] = red;
	color[1] = green;
	color[2] = blue;
}

void Objeto3D::dibuja() {}
void Objeto3D::_dibuja() {}