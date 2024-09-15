#pragma once

#include "Cirno/Events/Event.hpp"
#include "Cirno/Events/WindowEvent.hpp"
#include "Cirno/Defines.hpp"
#include "Cirno/Window.hpp"

#include <any>

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

    void OnEvent(BaseEvent &&e);
    
    void CRTPOnEvent(CRTP &&e);

public:
    void SetIsRunning(bool isRun) noexcept { m_IsRunning = isRun; }

private:
    bool OnWindowResize(WindowResizeEvent &e);
    bool OnCRTPWindowResize(CRTPWindowResizeEvent &e);
    bool OnWindowClose(WindowCloseEvent &e);

private:
    bool m_IsRunning = false;
    std::unique_ptr<Window> m_Window;

};

Application *CreateApplication();

}  // namespace Cirno