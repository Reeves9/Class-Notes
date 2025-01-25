#include <iostream>
#include <GL/glut.h>

using namespace std;

GLsizei wh = 500;
GLsizei ww = 500;

void Displaydot(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glVertex2i(40,210);
	glEnd();
	glFlush();
}

void MyInit(void){
	cout << glGetString(GL_VERSION) << endl;
	cout << glGetString(GL_VENDOR) << endl;
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(0.0f,1.0f,1.0f);
	glPointSize(10.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,(GLdouble)ww,0.0,(GLdouble)wh);
}

int main(int argc , char **argv){
	glutInit(&argc , argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(ww,wh);
	glutInitWindowPosition(180,90);
	glutCreateWindow("display a Dot");
	MyInit();
	glutDisplayFunc(Displaydot);
	glutMainLoop();
}
