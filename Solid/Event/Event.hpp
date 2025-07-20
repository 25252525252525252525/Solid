#ifndef SOLID_EVENT_EVENT_HPP
#define SOLID_EVENT_EVENT_HPP

#include <string>
namespace Solid::Event {

enum EventCategory {
    None = 0,
    Application = 1 << 0,
    Input = 1 << 1,
    Keyboard = 1 << 2,
    Mouse = 1 << 3,
    MouseButton = 1 << 4
};

enum class EventType {
    None = 0,
    WindowClose,
    WindowResize,
    WindowFocus,
    WindowLostFocus,
    WindowMoved,
    AppTick,
    AppUpdate,
    AppRender,
    KeyPressed,
    KeyReleased,
    KeyTyped,
    MouseButtonPressed,
    MouseButtonReleased,
    MouseMoved,
    MouseScrolled
};

class Event {
public:
    Event() = default;
    virtual ~Event() = default;
    virtual int getCategoryFlags() const = 0;
    virtual EventType getType() const = 0;
    virtual std::string getName() const = 0;

    virtual std::string toString() const
    {
        return getName();
    }

    bool isHandled_ = false;
};

}

#endif
