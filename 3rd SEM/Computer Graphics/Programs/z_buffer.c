#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Enable depth testing
    glEnable(GL_DEPTH_TEST);
    
    // Clear depth buffer
    glClearDepth(1.0);
    glDepthFunc(GL_LESS);
    
    // Draw objects
    glBegin(GL_TRIANGLES);
    
    glColor3f(1.0, 0.0, 0.0); // Red
    glVertex3f(-0.5, -0.5, -1.0);
    glVertex3f(0.0, 0.5, -2.0);
    glVertex3f(0.5, -0.5, -3.0);
    
    glColor3f(0.0, 1.0, 0.0); // Green
    glVertex3f(-0.5, 0.5, -2.5);
    glVertex3f(0.5, 0.5, -1.5);
    glVertex3f(0.0, -0.5, -3.5);
    
    glEnd();
    
    glFlush();
    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)width / height, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Z-Buffer Algorithm Example");
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    
    glutMainLoop();
    
    return 0;
}

