#pragma once

#include "Cirno/Layer.hpp"
#include "Cirno/Window.hpp"

#include <GLFW/glfw3.h>

namespace Cirno
{
class ImguiLayer : public Layer
{
public:
    ImguiLayer(Window *window) : Layer("ImguiLayer"), m_RefWindow(window) {}
    virtual ~ImguiLayer() = default;

    virtual void OnAttach() override;
    virtual void OnDetach() override;
    virtual void OnUpdate() override {}
    virtual void OnImguiDraw() override;

    void OnBegin();
    void OnEnd();

    virtual void OnEvent(Event& event) override;

private:
    Window *m_RefWindow = nullptr;
};

}