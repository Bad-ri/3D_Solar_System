#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include <ctime>
#include <cstdio>
#include<synchapi.h>
#include<iostream>
#include<sstream>
using namespace std;
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glut32.lib")


/*** Global Variables ***/

UINT prevFrameTime = -1;
float currAngle = 0;
float shear = 0.9;
double TX = 1.0;
int TY = 5;
int Rz = 1;
float SX = 1;
float SY = 1;

float earthAngle = 0;
float currXPosition = 0;
float sunAngle = 0;
float moonAngle = 0;

/**
Creates the main window, registers event handlers, and
initializes OpenGL stuff.
*/
void InitGraphics(int argc, char* argv[]);




/**
Sets the logical coordinate system we will use to specify
our drawings.
*/
void SetTransformations() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluOrtho2D(-100, 100, -100, 100);
	gluPerspective(60, (double)800 / 600, 1, 1000);

	gluLookAt(
		0, 60, 30,
		0, 0, 0,
		1, 0, 1
	);
}

boolean changeDirection = false;

void Update()
{


	sunAngle += 0.03;
	earthAngle += 0.1;
	moonAngle += 0.07;


}
void Draw_Cordinates()
{

	glLineWidth(5);
	glBegin(GL_LINES);
	glColor3f(0, 1, 0);
	// X-axis
	glVertex3f(-100, 0, 0);
	glVertex3f(100, 0, 0);
	//Y-axis
	glVertex3f(0, -100, 0);
	glVertex3f(0, 100, 0);
	glEnd();
}

void OnDisplay() {
	//set the background color to white
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	SetTransformations();





	//glTranslatef(10, 0, 0);
	//glScalef(2, 1, 1);
	//glRotatef(-30,0,0,1);
	//glRotatef(Rz, 0, 1, 0);
	//glTranslated(TX,0,0);
	//glScalef(0.5,0.5,1);


	
	//glBegin(GL_TRIANGLES);
	//glColor3f(0, 0, 1);
	//glVertex3f(20, 0, 20);
	//glVertex3f(20, 0, -20);
	//glVertex3f(0, 20, 0);

	//glColor3f(1, 0, 0.5);
	//glVertex3f(20, 0, -20);
	//glVertex3f(-20, 0, -20);
	//glVertex3f(0, 20, 0);

	//glColor3f(0, 0, 1);
	//glVertex3f(-20, 0, -20);
	//glVertex3f(-20, 0, 20);
	//glVertex3f(0, 20, 0);

	//glColor3f(1, 0, 1);
	//glVertex3f(-20, 0, 20);
	//glVertex3f(20, 0, 20);
	//glVertex3f(0, 20, 0);
glTranslatef(0, 0, 0);
	glRotatef(sunAngle, 0, 1, 0);
	glPushMatrix();
	glColor3f(0.5, 0.5, 0);
	
	glutWireSphere(5, 30, 30);
	glPopMatrix();
	
glTranslatef(25, 0, 0);
	glRotatef(earthAngle, 0, 1, 0);
	glPushMatrix();
	glColor3f(0, 0, 1);
	
	glutWireSphere(3, 25, 25);
	glPopMatrix();
	
glTranslatef(10, 0, 0);
	glRotatef(moonAngle, 0, 1, 0);
	glPushMatrix();
	glColor3f(1, 1, 1);
	
	glutWireSphere(2, 10, 10);
	glPopMatrix();

	glFlush();
	glutSwapBuffers();
	//Translation update
	Update();
	glutPostRedisplay();
}

/**
Creates the main window, registers event handlers, and
initializes OpenGL stuff.
*/
void InitGraphics(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(550, 100); //pass (-1, -1) for Window-Manager defaults
	glutInitWindowSize(800, 600);
	glutCreateWindow("OpenGL Lab");
	glutDisplayFunc(OnDisplay);
	glutMainLoop();
}

int main(int argc, char* argv[]) {
	InitGraphics(argc, argv);
	return 0;
}