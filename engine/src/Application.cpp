#include "Cirno/Imgui/ImguiLayer.hpp"
#include "Cirno/Logger.hpp"

#include "Cirno/Application.hpp"
#include "Cirno/Events/Event.hpp"
#include "Cirno/Events/WindowEvent.hpp"
#include "Cirno/Events/KeyEvent.hpp"

#include <functional>
#include <algorithm>
#include <cassert>

namespace Cirno
{
Application *Application::s_Instance = nullptr;
static bool s_IsAppCreated = false;
static bool s_IsImguiLayerCreate = false;

Application::Application()
{
    // set singleton instance
    CIRNO_ASSERT(!s_IsAppCreated, "Application already created");
    s_Instance = this;
    s_IsAppCreated = true;

    m_Window = std::unique_ptr<Window>(Window::Create());
    m_Window->SetApplicationEventCallback(
        std::bind(&Application::OnEvent, this, std::placeholders::_1));

    // m_ImguiLayer = std::make_shared<ImguiLayer>();
    CIRNO_ASSERT(!s_IsImguiLayerCreate, "Imgui layer already created");
    m_ImguiLayer = new ImguiLayer();
    PushOverlay(m_ImguiLayer);
    s_IsImguiLayerCreate = true;

    m_IsRunning = true;
}

Application::~Application() {}

void Application::Run()
{
    while (m_IsRunning)
    {
        m_Window->OnUpdateStart();

        std::for_each(m_LayerStack.begin(), m_LayerStack.end(),
                      [](auto layer) { layer->OnUpdate(); });

        m_ImguiLayer->OnBegin();
        std::for_each(m_LayerStack.begin(), m_LayerStack.end(),
                      [](auto layer) { layer->OnImguiDraw(); });
        m_ImguiLayer->OnEnd();


        m_Window->OnUpdateEnd();
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

    for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
    {
        (*it)->OnEvent(e);
        if (e.IsHandled())
            break;
    }
}

void Application::PushLayer(Layer *layer)
{
    m_LayerStack.PushLayer(layer);
    layer->OnAttach();
}

void Application::PushOverlay(Layer *overlay)
{
    m_LayerStack.PushOverlay(overlay);
    overlay->OnAttach();
}

bool Application::OnWindowResize(WindowResizeEvent &e)
{
    INTERNAL_DEBUG(e);
    return true;
}

bool Application::OnWindowClose(WindowCloseEvent &e)
{
    INTERNAL_DEBUG(e);
    m_IsRunning = false;

    return true;
}

bool Application::OnKeyPressed(KeyPressedEvent &e)
{
    INTERNAL_DEBUG(e);
    return true;
}

bool Application::OnKeyReleased(KeyReleasedEvent &e)
{
    INTERNAL_DEBUG(e);
    return true;
}

}  // namespace Cirno