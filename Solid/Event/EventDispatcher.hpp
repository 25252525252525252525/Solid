#ifndef SOLID_EVENT_EVENT_DISPATCHER_HPP
#define SOLID_EVENT_EVENT_DISPATCHER_HPP

#include "Event/Event.hpp"
namespace Solid::Event {

class EventDispatcher {
public:
    EventDispatcher(Event& event)
        : event_(event)
    {
    }

    template <typename T, typename F>
    bool dispatch(const F& func)
    {
        if (event_.getType() == T::getStaticType()) {
            event_.isHandled |= func(static_cast<T&>(event_));
            return true;
        }

        return false;
    }

private:
    Event& event_;
};

}

#endif