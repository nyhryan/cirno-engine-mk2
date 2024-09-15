#pragma once

#include "Cirno/Window.hpp"

#define GLFW_INCLUDE_NONE
#include <glad/gl.h>
#include <GLFW/glfw3.h>

namespace Cirno
{

class CIRNO_API GLWindow : public Window
{
public:
    GLWindow(WindowProps &&props);
    ~GLWindow();

    void OnUpdate() override;

    unsigned int GetWidth() const override { return m_Data.width; }
    unsigned int GetHeight() const override { return m_Data.height; }

    void SetApplicationEventCallback(ApplicationEventCallback &&cb) override { m_Data.eventCallback = cb; }
    void SetVSync(bool isEnable) override;
    bool IsVSync() const override { return m_Data.isVSync; } 

private:
    void Init();
    void Shutdown();

private:
    GLFWwindow *m_Window = nullptr;
    
    struct WindowData
    {
        std::string title;
        unsigned int width = 0;
        unsigned int height = 0;
        bool isVSync = true;
        ApplicationEventCallback eventCallback;
    };

    WindowData m_Data;
};

}