#pragma once

#include "Cirno/Layer.hpp"
#include "Cirno/Defines.hpp"

#include <vector>
#include <algorithm>

namespace Cirno
{
class CIRNO_API LayerStack
{
public:
    LayerStack() = default;
    ~LayerStack()
    {
        std::for_each(m_Layers.begin(), m_Layers.end(), [](Layer *layer) {
            delete layer;
        });
    }

public:
    void PushLayer(Layer *layer);
    void PopLayer(Layer *layer);

    void PushOverlay(Layer *overlay);
    void PopOverlay(Layer *overlay);

    [[nodiscard]] std::vector<Layer *>::iterator begin()
    {
        return m_Layers.begin();
    }
    [[nodiscard]] std::vector<Layer *>::iterator end()
    {
        return m_Layers.end();
    }

    [[nodiscard]] std::vector<Layer *>::const_iterator cbegin() const
    {
        return m_Layers.begin();
    }
    [[nodiscard]] std::vector<Layer *>::const_iterator cend() const
    {
        return m_Layers.end();
    }

    [[nodiscard]] std::vector<Layer *>::reverse_iterator rbegin()
    {
        return m_Layers.rbegin();
    }
    [[nodiscard]] std::vector<Layer *>::reverse_iterator rend()
    {
        return m_Layers.rend();
    }

    [[nodiscard]] std::vector<Layer *>::const_reverse_iterator crbegin() const
    {
        return m_Layers.rbegin();
    }
    [[nodiscard]] std::vector<Layer *>::const_reverse_iterator crend() const
    {
        return m_Layers.rend();
    }

private:
    std::vector<Layer *> m_Layers;
};
}  // namespace Cirno