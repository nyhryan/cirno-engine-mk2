#include "Cirno/Application.hpp"
#include "Cirno/Events/Event.hpp"
#include "Cirno/Events/WindowEvent.hpp"

#include <iostream>
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

void Application::OnEvent(IEvent &&e)
{
    EventDispatcher d{e};

    auto dispatch = [&]<typename T>(Application::EventCallback<T> fn)
    {
        d.Dispatch<T>(std::bind(std::forward<Application::EventCallback<T>>(fn),
                                this, std::placeholders::_1));
    };

    dispatch(&Application::OnWindowResize);
    dispatch(&Application::OnWindowClose);
}

bool Application::OnWindowResize(WindowResizeEvent &e)
{
    std::cout << e.ToString() << "\n";
    return true;
}

bool Application::OnWindowClose(WindowCloseEvent &e)
{
    std::cout << e.ToString() << "\n";
    m_IsRunning = false;

    return true;
}

}  // namespace Cirno