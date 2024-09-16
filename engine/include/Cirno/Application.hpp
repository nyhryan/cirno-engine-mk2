#pragma once

#include "Cirno/Events/Event.hpp"
#include "Cirno/Events/WindowEvent.hpp"
#include "Cirno/Events/KeyEvent.hpp"
#include "Cirno/Defines.hpp"
#include "Cirno/Window.hpp"

#include <memory>

namespace Cirno
{

class CIRNO_API Application
{
public:
    Application();

    Application(const Application &) = delete;
    Application &operator=(const Application &) = delete;

    virtual ~Application();

    void Run();

    void OnEvent(Event &&e);
    
public:
    void SetIsRunning(bool isRun) noexcept { m_IsRunning = isRun; }

private:
    template <typename T>
    using EventCallback = bool (Cirno::Application::*)(T &);

    bool OnWindowResize(WindowResizeEvent &e);
    bool OnWindowClose(WindowCloseEvent &e);

    bool OnKeyPressed(KeyPressedEvent &e);
    bool OnKeyReleased(KeyReleasedEvent &e);

private:
    bool m_IsRunning = false;
    std::unique_ptr<Window> m_Window;

};

// To be defined by client
Application *CreateApplication();

}  // namespace Cirno