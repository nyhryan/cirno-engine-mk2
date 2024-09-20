#pragma once

#include "Cirno/Events/Event.hpp"
#include "Cirno/Logger.hpp"

#include <string_view>

namespace Cirno
{
class CIRNO_API Layer
{
public:
    Layer(std::string_view name = "Layer") : m_DebugName(name)
    {
        INTERNAL_DEBUG("Creating Layer {}...", m_DebugName);
    }
    virtual ~Layer()
    {
        INTERNAL_DEBUG("Destroying Layer {}...", m_DebugName);
    }

    virtual void OnAttach() {}
    virtual void OnDetach() {}
    virtual void OnUpdate() {}
    virtual void OnImguiDraw() {}

    virtual void OnEvent(Event& event) {}

    [[nodiscard]] std::string_view GetName() const { return m_DebugName; }

protected:  
    std::string m_DebugName;
};
}  // namespace Cirno