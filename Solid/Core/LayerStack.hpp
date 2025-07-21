#ifndef SOLID_CORE_LAYER_STACK_HPP
#define SOLID_CORE_LAYER_STACK_HPP

#include "Layer.hpp"

#include <memory>
#include <vector>

namespace Solid {

class LayerStack {
public:
    LayerStack();
    ~LayerStack() = default;
    void pushLayer(std::shared_ptr<Layer> layer);
    void popLayer(std::shared_ptr<Layer> layer);
    void pushOverlay(std::shared_ptr<Layer> layer);
    void popOverlay(std::shared_ptr<Layer> layer);

    inline std::vector<std::shared_ptr<Layer>>::iterator begin()
    {
        return stack_.begin();
    }
    inline std::vector<std::shared_ptr<Layer>>::iterator end()
    {
        return stack_.end();
    }
    inline std::vector<std::shared_ptr<Layer>>::reverse_iterator rbegin()
    {
        return stack_.rbegin();
    }
    inline std::vector<std::shared_ptr<Layer>>::reverse_iterator rend()
    {
        return stack_.rend();
    }

private:
    std::vector<std::shared_ptr<Layer>> stack_;
    std::vector<std::shared_ptr<Layer>>::iterator layerInsertPositionIt_;
};

}

#endif
