#ifndef Cubo_H_
#define Cubo_H_

#include "Malla.h"
 
class Cubo : public Malla {	 
	private:
		GLfloat colorX,colorY,colorZ;
    public:
        Cubo(GLfloat coorX,GLfloat coorY,GLfloat coorZ,GLfloat tamanho,GLfloat cX,GLfloat cY,GLfloat cZ);
        ~Cubo(); 
		void dibuja();
};
#endif