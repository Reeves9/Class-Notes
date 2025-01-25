#include <GLFW/glfw3.h>

int main() {
    // Initialize GLFW and create a window
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 600, "Pixel Example", NULL, NULL);
    glfwMakeContextCurrent(window);

    // Loop until the window is closed
    
    while (!glfwWindowShouldClose(window)) {
        // Clear the screen
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Set the pixel position in window coordinates
        int x = 400;
        int y = 300;

        // Map pixel position to NDC
        int windowWidth, windowHeight;
        glfwGetWindowSize(window, &windowWidth, &windowHeight);
        float ndcX = (2.0f * x) / windowWidth - 1.0f;
        float ndcY = 1.0f - (2.0f * y) / windowHeight;

        glColor3f(1.0f, 1.0f, 0.0f);
        // Render the pixel
        glBegin(GL_POINTS);
        glVertex2f(ndcX, ndcY);
        glEnd();

        // Swap buffers
        glfwSwapBuffers(window);

        // Poll for events
        glfwPollEvents();
    }

    // Cleanup
    glfwTerminate();

    return 0;
}

//Remember to link the OpenGL and GLFW libraries when compiling the program (e.g., using -lglfw -lGL flags).
