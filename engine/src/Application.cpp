#include "Cirno/Logger.hpp"

#include "Cirno/Application.hpp"
#include "Cirno/Events/Event.hpp"
#include "Cirno/Events/WindowEvent.hpp"
#include "Cirno/Events/KeyEvent.hpp"

#include <functional>

namespace Cirno
{

Application::Application()
{
    m_Window = std::unique_ptr<Window>(Window::Create());
    m_Window->SetApplicationEventCallback(
        std::bind(&Application::OnEvent, this, std::placeholders::_1)
    );
    m_IsRunning = true;
}

Application::~Application() {}

void Application::Run()
{
    while (m_IsRunning)
    {
        m_Window->OnUpdate();
    }
}

void Application::OnEvent(Event &&e)
{
    EventDispatcher d{e};

    auto dispatch = [&]<typename T>(Application::EventCallback<T> fn)
    {
        d.Dispatch<T>(std::bind(std::forward<Application::EventCallback<T>>(fn),
                                this, std::placeholders::_1));
    };

    dispatch(&Application::OnWindowResize);
    dispatch(&Application::OnWindowClose);
    dispatch(&Application::OnKeyPressed);
    dispatch(&Application::OnKeyReleased);
}

bool Application::OnWindowResize(WindowResizeEvent &e)
{
    INTERNAL_DEBUG("{}", e);
    return true;
}

bool Application::OnWindowClose(WindowCloseEvent &e)
{
    INTERNAL_DEBUG("{}", e);
    m_IsRunning = false;

    return true;
}

bool Application::OnKeyPressed(KeyPressedEvent &e)
{
    INTERNAL_DEBUG("{}", e);
    return true;
}

bool Application::OnKeyReleased(KeyReleasedEvent &e)
{
    INTERNAL_DEBUG("{}", e);
    return true;
}

}  // namespace Cirno