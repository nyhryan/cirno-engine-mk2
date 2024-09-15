#include "Cirno/Application.hpp"
#include "Cirno/Events/Event.hpp"
#include "Cirno/Events/WindowEvent.hpp"

#include <cstdlib>
#include <iostream>
#include <functional>

template <typename T>
inline static auto g_BindEvent(T &&func, Cirno::Application *_this)
    -> decltype(std::bind(std::forward<T>(func), _this, std::placeholders::_1))
{
    return std::bind(std::forward<T>(func), _this, std::placeholders::_1);
}

namespace Cirno
{

Application::Application()
{
    m_Window = std::unique_ptr<Window>(Window::Create());
    m_Window->SetApplicationEventCallback(g_BindEvent(&Application::CRTPOnEvent, this));
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

void Application::OnEvent(BaseEvent &&e)
{
    EventDispatcher d{e};
    d.Dispatch<WindowResizeEvent>(
        g_BindEvent(&Application::OnWindowResize, this));
    d.Dispatch<WindowCloseEvent>(
        g_BindEvent(&Application::OnWindowClose, this));
}

void Application::CRTPOnEvent(CRTP &&e)
{
    CRTPEventDispatcher d{e};
    d.Dispatch<CRTPWindowResizeEvent>(
        g_BindEvent(&Application::OnCRTPWindowResize, this));
    // d.Dispatch(g_BindEvent(&Application::OnWindowClose, this));
}

bool Application::OnWindowResize(WindowResizeEvent &e)
{
    std::cout << e.ToString() << "\n";
    return true;
}

bool Application::OnCRTPWindowResize(CRTPWindowResizeEvent &e)
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