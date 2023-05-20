#include <GL/glut.h>

void init2D(float r, float g, float b){
	glClearColor(r,g,b,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,200.0,0.0,150.0);
}

void Display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_POINTS);
	for(int i=0 ; i<10 ; i++){
		glVertex2i(10+5*i,110);
	}
	glEnd();
	glBegin(GL_LINES);
		glVertex2i(10,10);
		glVertex2i(100,100);
	glEnd();
	glFlush();
}

int main(int argc , char *argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(830,470);
	glutCreateWindow("Point and Lines");
	init2D(0.0,0.0,0.0);
	glutDisplayFunc(Display);
	glutMainLoop();
	return 0;
}
	
