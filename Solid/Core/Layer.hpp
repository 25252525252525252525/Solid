#ifndef SOLID_CORE_LAYER_HPP
#define SOLID_CORE_LAYER_HPP

#include "Event.hpp"

namespace Solid {

class Layer {
public:
    Layer() = default;
    virtual ~Layer() = default;
    virtual void onAttach() = 0;
    virtual void onDetach() = 0;
    virtual void onUpdate() = 0;
    virtual void onEvent(Event::Event& event) = 0;
};

}

#endif
