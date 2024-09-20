#pragma once

#include "Cirno/Events/WindowEvent.hpp"
#include "Cirno/Events/KeyEvent.hpp"
#include "Cirno/Window.hpp"
#include "Cirno/LayerStack.hpp"
#include "Cirno/Imgui/ImguiLayer.hpp"

#include <memory>

namespace Cirno
{

class CIRNO_API Application
{
public:
    Application();
    Application(const Application &) = delete;
    Application &operator=(const Application &) = delete;

    [[nodiscard]] static Application &GetInstance() noexcept
    {
        return *s_Instance;
    }

    virtual ~Application();

public:
    void Run();

    void OnEvent(Event &&e);

    void PushLayer(Layer *layer);
    void PushOverlay(Layer *overlay);

public:
    [[nodiscard]] Window &GetWindow() const { return *m_Window; }
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
    LayerStack m_LayerStack;
    ImguiLayer *m_ImguiLayer = nullptr;

    static Application *s_Instance;
};

// To be defined by client
Application *CreateApplication();

}  // namespace Cirno