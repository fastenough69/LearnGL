#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

//#define window_SizeX 640
//#define window_SizeY 480

int window_SizeX = 640;
int window_SizeY = 480;

float points[] = {
     0.0f, 0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     -0.5f, -0.5f, 0.0f
};

static void EscKeyCallback(GLFWwindow* pt_w, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(pt_w, GL_TRUE);
    }
}

static void WindowSizeCallback(GLFWwindow* pt_w, int widht, int heigth)
{
    window_SizeX = widht;
    window_SizeY = heigth;
    glViewport(0, 0, window_SizeX, window_SizeY);
}

int main(void)
{
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    
    GLFWwindow* pt_window = glfwCreateWindow(window_SizeX, window_SizeY, "Hello World", nullptr, nullptr);
    if (!pt_window)
    {
        glfwTerminate();
        return -1;
    }

    glfwSetWindowSizeCallback(pt_window, WindowSizeCallback);
    glfwSetKeyCallback(pt_window, EscKeyCallback);

    /* Make the window's context current */
    glfwMakeContextCurrent(pt_window);

    if(!gladLoadGL())
    {
        std::cout << "glad not found\n";
        return -1;
    }

    std::cout << "OpenGL version: " << GLVersion.major << '.' << GLVersion.minor << std::endl;

    glClearColor(1, 0, 0, 1);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(pt_window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(pt_window);

        /* Poll for and process events */
        glfwPollEvents();

    }

    glfwTerminate();
    return 0;
}