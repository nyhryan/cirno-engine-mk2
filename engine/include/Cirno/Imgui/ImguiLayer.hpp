#pragma once

#include "Cirno/Layer.hpp"
#include "Cirno/Logger.hpp"

namespace Cirno
{
class ImguiLayer : public Layer
{
public:
    ImguiLayer();
    virtual ~ImguiLayer();

    virtual void OnAttach() override;
    virtual void OnDetach() override;
    virtual void OnUpdate() override {}
    virtual void OnImguiDraw() override;

    void OnBegin();
    void OnEnd();

    virtual void OnEvent(Event& event) override;
};

}