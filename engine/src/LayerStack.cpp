#include "Cirno/LayerStack.hpp"

#include <algorithm>

namespace Cirno
{
void LayerStack::PushLayer(Layer *layer)
{
    m_Layers.emplace(begin(), layer);
}

void LayerStack::PopLayer(Layer *layer)
{
    auto it = std::find(begin(), end(), layer);
    if (it != end())
    {
        m_Layers.erase(it);
    }
}

void LayerStack::PushOverlay(Layer *overlay)
{
    m_Layers.emplace_back(overlay);
}

void LayerStack::PopOverlay(Layer *overlay)
{
    PopLayer(overlay);
}

}  // namespace Cirno