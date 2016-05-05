#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Coche.h"
#include "Pino.h"
#include "Roble.h"
#include "Abeto.h"
#include "Alamo.h"
#include "Esfera.h"
#include "Farola.h"
#include <GL/freeglut.h>
//#include <GL/glut.h>

#include <iostream>
using namespace std;

// Freeglut parameters
// Flag telling us to keep processing events
// bool continue_in_main_loop= true; //(**)

// Viewport size
int WIDTH= 500, HEIGHT= 500;

// Viewing frustum parameters
GLdouble xRight=10, xLeft=-xRight, yTop=10, yBot=-yTop, N=1, F=1000;

// Camera parameters
GLdouble eyeX=100.0, eyeY=100.0, eyeZ=100.0;
GLdouble lookX=0.0, lookY=0.0, lookZ=0.0;
GLdouble upX=0, upY=1, upZ=0;

// Scene variables
GLfloat angX, angY, angZ; 
Abeto *e1;
Roble *e2;
Pino *e3;
Alamo *e4;
Coche *e5;
Esfera *e6;
Farola *e7;

void buildSceneObjects() {	 
    angX=0.0f;
    angY=0.0f;
    angZ=0.0f;	

	e1 = new Abeto();
	e1->mT->setTraslada(0.0f, 0.0f, 6.0f);
	e2 = new Roble();
	e2->mT->setTraslada(0.0f, 0.0f, 12.0f);
	e3 = new Pino();
	e3->mT->setTraslada(0.0f, 0.0, 18.0f);
	e4 = new Alamo();
	e4->mT->setTraslada(0.0f, 0.0, 24.0f);
	e5 = new Coche();
	e5->mT->setTraslada(.0f, 2.2f, .0f);
	e6 = new Esfera(100000, 100000);
	e6->mT->setTraslada(15.0f, .0f, .0f);
	e6->mT->setEscala(10,10,10);
	e6->setColor(.5f, .5f, .5f);
	e7 = new Farola;
	e7->mT->setTraslada(0.0f, 0.0, 32.0f);
}

void initGL() {	 		 
	glClearColor(0.0f,0.0f,0.0f,1.0);

	glEnable(GL_COLOR_MATERIAL);
	glMaterialf(GL_FRONT, GL_SHININESS, 0.9f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH); // Shading by default

	buildSceneObjects();

	//Disable ambient Light
	GLfloat amb[] = { 0.0f, 0.0f, 0.0f, 1.0 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb);

	// Light0
	glEnable(GL_LIGHTING);  
	glEnable(GL_LIGHT0);
	GLfloat d0[]={0.7f,0.5f,0.5f,1.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, d0);
	GLfloat a0[]={0.3f,0.3f,0.3f,1.0f};
	glLightfv(GL_LIGHT0, GL_AMBIENT, a0);
	GLfloat s0[]={1.0f,1.0f,1.0f,1.0f};
	glLightfv(GL_LIGHT0, GL_SPECULAR, s0);
	GLfloat p0[]={25.0f, 25.0f, 25.0f, 1.0f};	 
	glLightfv(GL_LIGHT0, GL_POSITION, p0);

	// Light1
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	GLfloat d1[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, d1);
	GLfloat a1[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	glLightfv(GL_LIGHT1, GL_AMBIENT, a1);
	GLfloat s1[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	glLightfv(GL_LIGHT1, GL_SPECULAR, s1);
	GLfloat p1[] = { 0.0f, 0.0f, 25.0f, 0.0f };
	glLightfv(GL_LIGHT1, GL_POSITION, p1);

	// Camera set up
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, upX, upY, upZ);

	// Frustum set up
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();     
	glOrtho(xLeft, xRight, yBot, yTop, N, F);

	// Viewport set up
	glViewport(0, 0, WIDTH, HEIGHT);  	
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  

	glMatrixMode(GL_MODELVIEW);	 
	glPushMatrix();
	
	// Rotating the scene
	glRotatef(angX, 1.0f, 0.0f, 0.0f);
	glRotatef(angY, 0.0f, 1.0f, 0.0f);
	glRotatef(angZ, 0.0f, 0.0f, 1.0f);

	GLfloat p1[] = { 25.0f, 25.0f, 0.0f, 0.0f };
	glLightfv(GL_LIGHT1, GL_POSITION, p1);
		
	glLineWidth(1.5f);
	// Drawing axes
	glBegin( GL_LINES );			
		glColor3f(1.0,0.0,0.0); 
		glVertex3f(0, 0, 0);
		glVertex3f(20, 0, 0);	     

		glColor3f(0.0,1.0,0.0); 
		glVertex3f(0, 0, 0);
		glVertex3f(0, 20, 0);	 

		glColor3f(0.0,0.0,1.0); 
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 20);	     
	glEnd();

	e1->dibuja();
	e2->dibuja();
	e3->dibuja();
	e4->dibuja();
	e5->dibuja();
	e6->dibuja();
	e7->dibuja();

	// Drawing the scene	 		 
	glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}


void resize(int newWidth, int newHeight) {
	WIDTH= newWidth;
	HEIGHT= newHeight;
	GLdouble RatioViewPort= (float)WIDTH/(float)HEIGHT;
	glViewport (0, 0, WIDTH, HEIGHT) ;

	GLdouble SVAWidth= xRight-xLeft;
	GLdouble SVAHeight= yTop-yBot;
	GLdouble SVARatio= SVAWidth/SVAHeight;
	if (SVARatio >= RatioViewPort) {		 
		GLdouble newHeight= SVAWidth/RatioViewPort;
		GLdouble yMiddle= ( yBot+yTop )/2.0;
		yTop= yMiddle + newHeight/2.0;
		yBot= yMiddle - newHeight/2.0;
	}
	else {      
		GLdouble newWidth= SVAHeight*RatioViewPort;
		GLdouble xMiddle= ( xLeft+xRight )/2.0;
		xRight= xMiddle + newWidth/2.0;
		xLeft=  xMiddle - newWidth/2.0;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();   
	glOrtho(xLeft, xRight, yBot, yTop, N, F);
}

void key(unsigned char key, int x, int y){
	bool need_redisplay = true;
	switch (key) {
		case 27:  /* Escape key */
			//continue_in_main_loop = false; // (**)
			//Freeglut's sentence for stopping glut's main loop (*)
			glutLeaveMainLoop (); 
			break;		 
		case 'a': angX=angX+5; break;
		case 'z': angX=angX-5; break; 
		case 's': angY=angY+5; break;
		case 'x': angY=angY-5; break;
		case 'd': angZ=angZ+5; break;
		case 'c': angZ=angZ-5; break;
		case 'q': e5->avanza(0.1f); break;
		case 'w': e5->avanza(-0.1f); break;
		case 't': e5->lightOn(); break;
		case 'y': e5->lightOff(); break;
		case 'r': e7->lightOn(); break;
		case 'f': e7->lightOff(); break;
		case 'u': glEnable(GL_LIGHT1);; break;
		case 'i': glDisable(GL_LIGHT1);; break;
		case 'g': glEnable(GL_LIGHT0);; break;
		case 'j': glDisable(GL_LIGHT0);; break;
		case '1': e5->avanzaGiro(0.1f, 0.5f); break;
		case '2': e5->avanzaGiro(0.1f, -0.5f); break;
		case '3': e5->avanzaGiro(-0.1f, 0.5f); break;
		case '4': e5->avanzaGiro(-0.1f, -0.5f); break;
		default:
			  need_redisplay = false;
			  break;
	}

	if (need_redisplay)
		glutPostRedisplay();
}

void keyUp(unsigned char key, int x, int y){
	bool need_redisplay = true;
	switch (key) {
	case '1': e5->resetRuedas(0.5f); break;
	case '2': e5->resetRuedas(-0.5f); break;
	case '3': e5->resetRuedas(0.5f); break;
	case '4': e5->resetRuedas(-0.5f); break;
	default:
		need_redisplay = false;
		break;
	}

	if (need_redisplay)
		glutPostRedisplay();
}

int main(int argc, char *argv[]){
	cout<< "Starting console..." << endl;

	int my_window; // my window's identifier

	// Initialization
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition (0, 0);
	//glutInitWindowPosition (140, 140);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInit(&argc, argv);

	// Window construction
	my_window = glutCreateWindow("Freeglut 3D-project");

	// Callback registration
	glutReshapeFunc(resize);
	glutKeyboardFunc(key);
	glutKeyboardUpFunc(keyUp);
	glutDisplayFunc(display);

	// OpenGL basic setting
	initGL();

	// Freeglut's main loop can be stopped executing (**)
	// while (continue_in_main_loop) glutMainLoopEvent();

	// Classic glut's main loop can be stopped after X-closing the window,
	// using the following freeglut's setting (*)
	glutSetOption (GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION) ;

	// Classic glut's main loop can be stopped in freeglut using (*)
	glutMainLoop(); 

	// We would never reach this point using classic glut
	system("PAUSE"); 

	return 0;
}
