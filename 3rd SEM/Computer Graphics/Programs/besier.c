#include <GL/glut.h>
#include <math.h>

//float pow(float num, float power){
//  float ans=1;
//  int i;
//  for (i = 1; i <= power; i++){
//    ans = ans * num;
//  }
//  return ans;
//}
// Define control points
float controlPoints[][3] = {
    {4.0, -2.0, 0.0},
    {1.0, -8.0, 0.0},
    {12.0, -1.0, 0.0},
    {2.0, -5.0, 0.0}
};

// Calculate the blending function for a given t
float blendingFunction(int i, int n, float t) {
    float choose = 1.0;
    for (int j = 1; j <= i; j++) {
        choose *= (float)(n - j + 1) / j;
    }
    return choose * pow(t, i) * pow(1 - t, n - i);
}

// Calculate the position on the curve for a given t
void calculateCurvePoint(float t, float* x, float* y, float* z) {
    int n = sizeof(controlPoints) / sizeof(controlPoints[0]) - 1;
    *x = *y = *z = 0.0;
    
    for (int i = 0; i <= n; i++) {
        float b = blendingFunction(i, n, t);
        *x += b * controlPoints[i][0];
        *y += b * controlPoints[i][1];
        *z += b * controlPoints[i][2];
    }
}

// Render the scene
void renderScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    
    glBegin(GL_LINE_STRIP);
    for (float t = 0.0; t <= 1.0; t += 0.01) {
        float x, y, z;
        calculateCurvePoint(t, &x, &y, &z);
        glVertex3f(x, y, z);
    }
    glEnd();
    
    glFlush();
}

// Initialize OpenGL settings
void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bézier Curve");
    
    init();
    
    glutDisplayFunc(renderScene);
    
    glutMainLoop();
    
    return 0;
}

