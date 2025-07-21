#include "LayerStack.hpp"
#include "Layer.hpp"

#include <algorithm>

namespace Solid {

LayerStack::LayerStack()
    : layerInsertPositionIt_(stack_.begin())
{
}

void LayerStack::pushLayer(std::shared_ptr<Layer> layer)
{
    layerInsertPositionIt_ = stack_.emplace(layerInsertPositionIt_, layer);
    ++layerInsertPositionIt_;
}

void LayerStack::popLayer(std::shared_ptr<Layer> layer)
{
    auto layerIt = std::find(stack_.begin(), stack_.end(), layer);
    if (layerIt != stack_.end()) {
        stack_.erase(layerIt);
        if (layerInsertPositionIt_ != stack_.begin()) {
            layerInsertPositionIt_--;
        }
    }
}

void LayerStack::pushOverlay(std::shared_ptr<Layer> layer)
{
    stack_.emplace_back(layer);
}

void LayerStack::popOverlay(std::shared_ptr<Layer> layer)
{
    auto layerIt = std::find(stack_.begin(), stack_.end(), layer);
    if (layerIt != stack_.end()) {
        stack_.erase(layerIt);
    }
}

}
