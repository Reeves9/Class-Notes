#include <GL/freeglut.h>

void display() {
  // Clear the screen and the depth buffer.
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Draw a white quad in the center of the screen.
  glColor3f(1.0f, 1.0f, 1.0f);
  glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
  glEnd();

  // Draw the button.
  glColor3f(0.0f, 0.0f, 1.0f);
  glRectf(-0.25f, -0.25f, 0.25f, 0.25f);

  // Print the text "Hello" on the button.
  glColor3f(1.0f, 1.0f, 1.0f);
  glRasterPos2f(-0.15f, 0.15f);
  glutBitmapString(GLUT_BITMAP_HELVETICA_18, "Hello");

  // Swap the buffers.
  glutSwapBuffers();
}

void reshape(int w, int h) {
  // Set the viewport to the size of the window.
  glViewport(0, 0, w, h);

  // Set the projection matrix.
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f, (float)w / (float)h, 1.0f, 100.0f);

  // Set the modelview matrix.
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void mouse(int button, int state, int x, int y) {
  // Do nothing.
}

void keyboard(unsigned char key, int x, int y) {
  // If the escape key is pressed, exit the program.
  if (key == 27) {
    glutDestroyWindow(glutGetWindow());
    exit(0);
  }
}

int main(int argc, char** argv) {
  // Initialize GLUT.
  glutInit(&argc, argv);

  // Create a window.
  glutCreateWindow("Hello World");

  // Set the display function.
  glutDisplayFunc(display);

  // Set the reshape function.
  glutReshapeFunc(reshape);

  // Set the mouse function.
  glutMouseFunc(mouse);

  // Set the keyboard function.
  glutKeyboardFunc(keyboard);

  // Enter the main loop.
  glutMainLoop();

  return 0;
}
