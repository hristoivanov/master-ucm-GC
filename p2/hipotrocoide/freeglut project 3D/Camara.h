 
#ifndef CamaraH
#define CamaraH

#include "PuntoVector3D.h"
#include "Extrusion.h"
 
class Camara {
	private:
		PuntoVector3D *eye, *up, *look, *u, *v, *n;				
        GLfloat left, right, bottom, top, Near, Far;                
        GLdouble fovy, aspect; 	
		Extrusion* t1;
		GLfloat posExtrusion;
		bool orto;

		void setView();	
		void setCameraCoordinateSystem();
        void setModelViewMatrix();

	public:				
		Camara();		 
                                                                     
        void giraX();
        void giraY();
        void giraZ();
        void lateral();
        void frontal();
        void cenital();
        void rincon(); 
		void setProjection(bool orto); 
		void roll(float ang);
        void pitch(float ang);
        void yaw(float ang);

		void setExtrusion(Extrusion* t1);
		void moveExtrusion(GLfloat inc);
};
#endif
