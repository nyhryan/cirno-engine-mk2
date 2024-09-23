#include "Cirno/LayerStack.hpp"

#include <algorithm>

namespace Cirno
{
LayerStack::~LayerStack()
{
    for (Layer *layer : m_Layers)
        delete layer;
}

inline void LayerStack::PushLayer(Layer * layer) { m_Layers.emplace(m_Layers.begin(), layer); }

inline void LayerStack::PopLayer(Layer * layer)
{
    auto it = std::remove(begin(), end(), layer);
    if (it != m_Layers.end())
    {
        m_Layers.erase(it, m_Layers.end());
        delete layer;
    }
}

inline void LayerStack::PushOverlay(Layer * overlay) { m_Layers.emplace_back(overlay); }

inline void LayerStack::PopOverlay(Layer * overlay) { PopLayer(overlay); }

}  // namespace Cirno