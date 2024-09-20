#pragma once

#include "Cirno/Layer.hpp"
#include "Cirno/Defines.hpp"

#include <vector>

namespace Cirno
{
class CIRNO_API LayerStack
{
    using LayerPtr = Layer*;
    using LayerVector = std::vector<LayerPtr>;
public:
    LayerStack() = default;
    ~LayerStack();

public:
    void PushLayer(LayerPtr layer);
    void PopLayer(LayerPtr layer);

    void PushOverlay(LayerPtr overlay);
    void PopOverlay(LayerPtr overlay);

    [[nodiscard]] LayerVector::iterator begin()
    {
        return m_Layers.begin();
    }
    [[nodiscard]] LayerVector::iterator end()
    {
        return m_Layers.end();
    }

    [[nodiscard]] LayerVector::const_iterator cbegin() const
    {
        return m_Layers.begin();
    }
    [[nodiscard]] LayerVector::const_iterator cend() const
    {
        return m_Layers.end();
    }

    [[nodiscard]] LayerVector::reverse_iterator rbegin()
    {
        return m_Layers.rbegin();
    }
    [[nodiscard]] LayerVector::reverse_iterator rend()
    {
        return m_Layers.rend();
    }

    [[nodiscard]] LayerVector::const_reverse_iterator crbegin() const
    {
        return m_Layers.rbegin();
    }
    [[nodiscard]] LayerVector::const_reverse_iterator crend() const
    {
        return m_Layers.rend();
    }

private:
    LayerVector m_Layers;
};
}  // namespace Cirno