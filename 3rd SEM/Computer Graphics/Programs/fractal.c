#include <GL/glut.h>
#include <math.h>

// Number of recursion levels
int recursionLevel = 5;

void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

void generateSierpinski(float x1, float y1, float x2, float y2, float x3, float y3, int level) {
    if (level == 0) {
        drawTriangle(x1, y1, x2, y2, x3, y3);
        return;
    }
    
    // Calculate midpoints of the sides
    float mid1x = (x1 + x2) / 2;
    float mid1y = (y1 + y2) / 2;
    float mid2x = (x2 + x3) / 2;
    float mid2y = (y2 + y3) / 2;
    float mid3x = (x1 + x3) / 2;
    float mid3y = (y1 + y3) / 2;
    
    // Calculate the new vertex
    float newX = (mid1x + mid2x + mid3x) / 3;
    float newY = (mid1y + mid2y + mid3y) / 3;
    
    generateSierpinski(x1, y1, mid1x, mid1y, mid3x, mid3y, level - 1);
    generateSierpinski(mid1x, mid1y, x2, y2, mid2x, mid2y, level - 1);
    generateSierpinski(mid3x, mid3y, mid2x, mid2y, x3, y3, level - 1);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Define triangle vertices
    float x1 = -0.5;
    float y1 = -0.433;
    float x2 = 0.5;
    float y2 = -0.433;
    float x3 = 0.0;
    float y3 = 0.433;
    
    glColor3f(1.0, 1.0, 1.0); // White color
    generateSierpinski(x1, y1, x2, y2, x3, y3, recursionLevel);
    
    glFlush();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Sierpinski Triangle");
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    
    glutMainLoop();
    
    return 0;
}

