 
#ifndef CamaraH
#define CamaraH

#include "PuntoVector3D.h"
 
class Camara {
	private:
		PuntoVector3D *eye, *up, *look, *u, *v, *n;               
        GLdouble fovy, aspect; 		 

		void setView();	
		void setCameraCoordinateSystem();
        //void setModelViewMatrix();

	public:
		GLfloat left, right, bottom, top, Near, Far;
		void setModelViewMatrix();
		Camara();		 
                                                                     
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
};
#endif
