#pragma once

#include "Cirno/Layer.hpp"
#include "Cirno/Defines.hpp"

#include <vector>

namespace Cirno
{
class CIRNO_API LayerStack
{
public:
   
    LayerStack() = default;
    ~LayerStack();

public:
    void PushLayer(Layer * layer);
    void PopLayer(Layer * layer);

    void PushOverlay(Layer * overlay);
    void PopOverlay(Layer * overlay);

    [[nodiscard]] auto begin() noexcept { return m_Layers.begin(); }
    [[nodiscard]] auto end() noexcept { return m_Layers.end(); }

    [[nodiscard]] auto cbegin() const noexcept { return m_Layers.cbegin(); }
    [[nodiscard]] auto cend() const noexcept { return m_Layers.cend(); }

    [[nodiscard]] auto rbegin() noexcept { return m_Layers.rbegin(); }
    [[nodiscard]] auto rend() noexcept { return m_Layers.rend(); }

    [[nodiscard]] auto crbegin() const noexcept { return m_Layers.crbegin(); }
    [[nodiscard]] auto crend() const noexcept { return m_Layers.crend(); }

private:
    std::vector<Layer *> m_Layers;
};
}  // namespace Cirno