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
#include "Camara2D.h"
#include "Simple2D.h"
#include "List.h"
#include "QuadtreeNode.h"

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

// Scene variables
GLfloat angX, angY, angZ; 

//Camara
Camara2D* c0;

//Quadtree related
int rows = 100, columns = 100;
List* theList;
QuadtreeNode* theQuadtree;
bool isFrustumCulled = true;


void buildSceneObjects() {	 
    angX=0.0f;
    angY=0.0f;
    angZ=0.0f;	

	theList = new List();
	Objeto3D* obj;
	int x, z;
	int intTree;
	float altura, anchura;
	for (x=0; x<rows*10; x+=10){
		for (z=0; z<columns*10; z+=10){
			altura = .9f + (static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) * .2f;
			anchura = .9f + (static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) * .2f;
			intTree = rand() % 4;
			if (intTree == 0)
				obj = new Abeto();
			if (intTree == 1)
				obj = new Alamo();
			if (intTree == 2)
				obj = new Pino();
			if (intTree == 3)
				obj = new Roble();

			obj->setTraslada(x, 0, z);
			obj->setEscala(anchura, altura, anchura);
			theList->add(obj);
		}	
	}

	theQuadtree = new QuadtreeNode(.0f, .0f, rows*10.0f, columns*10.0f, theList);
}

void initGL() {	 		 
	glClearColor(0.6f,0.7f,0.8f,1.0);

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
	GLfloat d0[]={.6f, .6f, .6f, 1.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, d0);
	GLfloat a0[]={.1f, .1f, .1f, 1.0f};
	glLightfv(GL_LIGHT0, GL_AMBIENT, a0);
	GLfloat s0[]={.0f, .0f, .0f, 1.0f};
	glLightfv(GL_LIGHT0, GL_SPECULAR, s0);
	GLfloat p0[]={25.0f, 25.0f, 25.0f, 1.0f};	 
	glLightfv(GL_LIGHT0, GL_POSITION, p0);

	c0 = new Camara2D();

	// Viewport set up
	glViewport(0, 0, WIDTH, HEIGHT);
}

void drawScene(void){
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
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0, 0, 0);
	glVertex3f(20, 0, 0);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 20, 0);

	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 20);
	glEnd();

	if(!isFrustumCulled){
		struct List::Node* n = theList->head;
		while(n != NULL){
			n->elem->dibuja();
			n = n->next;
		}
	}else{
		theQuadtree->draw(c0->get2D());
	}

	// Drawing the scene	 		 
	glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	drawScene();

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

	// TODO c0->resize(RatioViewPort)
	c0->setProjection();
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

		case 'q': c0->moveForward(); break;
		case 'w': c0->rotate(.3f); break;
		case 'e': c0->rotate(-.3f); break;

		case 'o': isFrustumCulled = true; break;
		case 'p': isFrustumCulled = false; break;


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
		default:
			need_redisplay = false;
			break;
	}

	if (need_redisplay)
		glutPostRedisplay();
}

int main(int argc, char *argv[]){
	cout<< "Starting console..." << endl;

	cout << "a/z, s/x, d/c  --> Rotaciones habituales." << endl;
	cout << "q, w, e        --> Mover la camara." << endl;
	cout << "o, p,          --> isFrustumCulled True/False." << endl;

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
