#include "Cirno/Application.hpp"

#include <cstdlib>
#include <glad/gl.h>
#include <GLFW/glfw3.h>

extern Cirno::Application *Cirno::CreateApplication();

int main(int, char **)
{
    Cirno::CreateApplication();


    if (!glfwInit())
        std::exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

    auto win = glfwCreateWindow(640, 480, "Demo", nullptr, nullptr);
    if (!win)
    {
        glfwTerminate();
        std::exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(win);
    gladLoadGL(glfwGetProcAddress);
    glfwSwapInterval(1);

    while (!glfwWindowShouldClose(win))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(win);
        glfwPollEvents();
    }

    glfwTerminate();
}