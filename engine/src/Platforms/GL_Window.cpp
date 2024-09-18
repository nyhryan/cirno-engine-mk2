#include "Cirno/Platforms/GL_Window.hpp"

#include "Cirno/Application.hpp"
#include "Cirno/Events/WindowEvent.hpp"
#include "Cirno/Events/KeyEvent.hpp"

#define GLFW_INCLUDE_NONE
#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <cassert>

template <typename T>
inline static void g_SetUserPointer(GLFWwindow *win, T *ptr)
{
    glfwSetWindowUserPointer(win, static_cast<void *>(ptr));
}

template <typename T>
inline static T *g_GetUserPointer(GLFWwindow *win)
{
    return static_cast<T *>(glfwGetWindowUserPointer(win));
}

namespace Cirno
{

static bool s_IsGLFWInitialized = false;

Window *Window::Create(WindowProps &&props)
{
    return new GLWindow(std::forward<WindowProps>(props));
}

GLWindow::GLWindow(WindowProps &&props)
{
    m_Data.title = props.title;
    m_Data.width = props.width;
    m_Data.height = props.height;

    Init();
}

GLWindow::~GLWindow() { Shutdown(); }

void GLWindow::Init()
{
    if (!s_IsGLFWInitialized)
    {
        int isSuccess = glfwInit();

        assert((isSuccess == GLFW_TRUE) && "glfwInit failed...");

        s_IsGLFWInitialized = true;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

    m_Window = glfwCreateWindow(static_cast<int>(m_Data.width),
                                static_cast<int>(m_Data.height),
                                m_Data.title.c_str(), nullptr, nullptr);

    glfwMakeContextCurrent(m_Window);
    gladLoadGL(glfwGetProcAddress);

    g_SetUserPointer<GLWindow::WindowData>(m_Window, &m_Data);

    glfwSwapInterval(1);
    SetVSync(true);

    glfwSetWindowSizeCallback(
        m_Window,
        [](GLFWwindow *win, int w, int h)
        {
            auto *windowData = g_GetUserPointer<GLWindow::WindowData>(win);
            windowData->width = w;
            windowData->height = h;
            windowData->applicationOnEvent(Cirno::WindowResizeEvent{w, h});
        });

    glfwSetFramebufferSizeCallback(
        m_Window,
        [](GLFWwindow *win, int w, int h)
        {
            glViewport(0, 0, w, h);
        });

    glfwSetWindowCloseCallback(
        m_Window,
        [](GLFWwindow *win)
        {
            auto *windowData = g_GetUserPointer<GLWindow::WindowData>(win);
            windowData->applicationOnEvent(Cirno::WindowCloseEvent{});
        });

    glfwSetKeyCallback(
        m_Window,
        [](GLFWwindow *win, int key, int scancode, int action, int mods)
        {
            auto *windowData = g_GetUserPointer<GLWindow::WindowData>(win);
            switch (action)
            {
                case GLFW_PRESS:
                {
                    windowData->applicationOnEvent(
                        Cirno::KeyPressedEvent{scancode, 0});
                    break;
                }

                case GLFW_RELEASE:
                {
                    windowData->applicationOnEvent(
                        Cirno::KeyReleasedEvent{scancode});
                    break;
                }

                case GLFW_REPEAT:
                {
                    windowData->applicationOnEvent(
                        Cirno::KeyPressedEvent{scancode, 1});
                    break;
                }
            }
        });
}

void GLWindow::Shutdown()
{
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}

void GLWindow::OnUpdateStart()
{
    glClear(GL_COLOR_BUFFER_BIT);

    auto &win = Application::GetInstance().GetWindow();
    glViewport(0, 0, win.GetWidth(), win.GetHeight());

    glfwPollEvents();
}

void GLWindow::OnUpdateEnd()
{
    glfwSwapBuffers(m_Window);
}

void GLWindow::SetVSync(bool isEnable)
{
    if (isEnable)
    {
        glfwSwapInterval(1);
        m_Data.isVSync = true;
    }
    else
    {
        glfwSwapInterval(0);
        m_Data.isVSync = false;
    }
}

}  // namespace Cirno