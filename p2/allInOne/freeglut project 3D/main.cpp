#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "Coche.h" 
#include "Pino.h"
#include "Roble.h"
#include "Abeto.h"
#include "Alamo.h"
#include "Camara.h"
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

//Camaras
Camara *c0;
Camara *c1;
Camara *c2;
Camara *c3;

//Embaldosado
bool baldosas = true;
int nCol = 2;


void buildSceneObjects() {	 
    angX=0.0f;
    angY=0.0f;
    angZ=0.0f;	

	e1 = new Abeto();
	e1->setPosicion(-12, 0.0, -5);
	e2 = new Roble();
	e2->setPosicion(-4, 0.0, -5);
	e3 = new Pino();
	e3->setPosicion(4, 0.0, -5);
	e4 = new Alamo();
	e4->setPosicion(12, 0.0, -5);


	e5 = new Coche();
}

void initGL() {	 		 
	glClearColor(0.6f,0.7f,0.8f,1.0);

	glEnable(GL_COLOR_MATERIAL);
	glMaterialf(GL_FRONT, GL_SHININESS, 0.9f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH); // Shading by default

	buildSceneObjects();

	// Light0
	glEnable(GL_LIGHTING);  
	glEnable(GL_LIGHT0);
	GLfloat d[]={0.7f,0.5f,0.5f,1.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, d);
	GLfloat a[]={0.3f,0.3f,0.3f,1.0f};
	glLightfv(GL_LIGHT0, GL_AMBIENT, a);
	GLfloat s[]={1.0f,1.0f,1.0f,1.0f};
	glLightfv(GL_LIGHT0, GL_SPECULAR, s);
	GLfloat p[]={25.0f, 25.0f, 25.0f, 1.0f};	 
	glLightfv(GL_LIGHT0, GL_POSITION, p);

	c0 = new Camara();
	c0->lateral();
	c1 = new Camara();
	c1->frontal();
	c2 = new Camara();
	c2->cenital();
	c3 = new Camara();
	c3->rincon();

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

	e1->dibuja();
	e2->dibuja();
	e3->dibuja();
	e4->dibuja();

	e5->dibuja();

	// Drawing the scene	 		 
	glColor3f(1.0, 1.0, 1.0);
	glPopMatrix();
}

void embaldosar(int nCol){
	GLdouble SVAratio = (xRight - xLeft) / (yTop - yBot);
	GLdouble w = (GLdouble)WIDTH / (GLdouble)nCol;
	GLdouble h = w / SVAratio;

	int count_aux = 0;
	for (GLint c = 0; c<nCol; c++){
		GLdouble currentH = 0;
		while ((currentH + h) <= HEIGHT){
			glViewport((GLint)(c*w), (GLint)currentH, (GLint)w, (GLint)h);
			if (count_aux == 0){ c0->setProjection(); c0->setModelViewMatrix();}
			if (count_aux == 1){ c1->setProjection(); c1->setModelViewMatrix();}
			if (count_aux == 2){ c2->setProjection(); c2->setModelViewMatrix();}
			if (count_aux == 3){ c3->setProjection(); c3->setModelViewMatrix();} 
			drawScene(); //dibujar la escena
			currentH += h;
			count_aux += 1;
		}
	}
}

void desembaldosar(void){
	glViewport(0, 0, WIDTH, HEIGHT);
	c3->setModelViewMatrix();
	baldosas = false;
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (baldosas) embaldosar(nCol);
	else drawScene();

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

		//TODO
		case 'f': e5->avanza(0.1f); break;
		case 'v': e5->avanza(-0.1f); break;
		//TODO

		case '1': c3->giraX(); break;
		case '2': c3->giraY(); break;
		case '3': c3->giraZ(); break;

		case '4': c3->lateral(); break;
		case '5': c3->frontal(); break;
		case '6': c3->cenital(); break;
		case '7': c3->rincon(); break;

		case 'p': c3->changeProyection(); break;

		case 'q': c3->roll(0.9f); break;
		case 'w': c3->yaw(0.9f); break;
		case 'e': c3->pitch(0.9f); break;

		case '8': baldosas = true; break;
		case '9': baldosas = false; desembaldosar(); break;

		case 'i': c3->zoom(0.95f); break;
		case 'k': c3->zoom(1.05f); break;

		default:
			  need_redisplay = false;
			  break;
	}

	if (need_redisplay)
		glutPostRedisplay();
}

int main(int argc, char *argv[]){
	cout<< "Starting console..." << endl;

	cout << "a/z, s/x, d/c	--> Rotaciones habituales." << endl;
	cout << "1, 2, 3		--> Rotaciones de la camara alrededor de los ejes." << endl;
	cout << "4, 5, 6, 7		--> Vistas lateral, frontal, cenital, rincon." << endl;
	cout << "p				--> Cambiar de proyeccion, perspectiva u ortogonal." << endl;
	cout << "q, w, e		--> Rotaciones de la camara: roll, yaw, pitch." << endl;
	cout << "8, 9			--> Embaldosar, Desembaldosar." << endl;
	cout << "i, k			--> ZoomIn, ZoomOut." << endl;


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
