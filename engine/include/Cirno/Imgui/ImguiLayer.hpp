#pragma once

#include "Cirno/Layer.hpp"

namespace Cirno
{
class ImguiLayer : public Layer
{
public:
    ImguiLayer() : Layer("ImguiLayer") {}
    ~ImguiLayer() = default;

    virtual void OnAttach() override;
    virtual void OnDetach() override;
    virtual void OnUpdate() override {}
    virtual void OnImguiDraw() override;

    void OnBegin();
    void OnEnd();

    virtual void OnEvent(Event& event) override;
};

}