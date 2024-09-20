#include "Cirno/LayerStack.hpp"

#include <algorithm>

namespace Cirno
{
LayerStack::~LayerStack()
{
    // std::for_each(m_Layers.begin(), m_Layers.end(), [](Layer *layer) {
    //     delete layer;
    // });
    for (Layer *layer : m_Layers)
    {
        delete layer;
    }
}

void LayerStack::PushLayer(Layer *layer) { m_Layers.emplace(begin(), layer); }

void LayerStack::PopLayer(Layer *layer)
{
    // auto it = std::find(begin(), end(), layer);
    // if (it != end())
    // {
    //     m_Layers.erase(it);
    // }
    auto it = std::remove(begin(), end(), layer);
}

void LayerStack::PushOverlay(Layer *overlay) { m_Layers.emplace_back(overlay); }

void LayerStack::PopOverlay(Layer *overlay) { PopLayer(overlay); }

}  // namespace Cirno