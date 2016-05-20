#ifndef Camara_H
#define Camara_H

#include "PuntoVector3D.h"
 
class Camara {
	private:
		PuntoVector3D *eye, *up, *look, *u, *v, *n;				
        GLfloat left, right, bottom, top, Near, Far;                
        GLdouble fovy, aspect; 	
		bool proyection;

		void setView();	
		void setCameraCoordinateSystem();

	public:				
		Camara();	
		void setModelViewMatrix();
                                                                     
        void giraX();
        void giraY();
        void giraZ();
        void lateral();
        void frontal();
        void cenital();
        void rincon(); 
		void setProjection(); 
		void roll(float ang);
        void pitch(float ang);
        void yaw(float ang);   
		void changeProyection();
		void zoom(float amount);
};
#endif
