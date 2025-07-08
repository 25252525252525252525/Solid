#ifndef SOLID_EVENT_KEY_EVENT_HPP
#define SOLID_EVENT_KEY_EVENT_HPP

#include "Event.hpp"
#include "KeyCode.hpp"

namespace Solid::Events {

class KeyEvent : public Event {
public:
    int getCategoryFlags() const override { return EventCategory::Keyboard | EventCategory::Input; }

    KeyCode getKeyCode() const { return keyCode_; }

protected:
    KeyEvent(KeyCode keyCode)
        : keyCode_(keyCode)
    {
    }

    KeyCode keyCode_;
};

class KeyPressedEvent : public KeyEvent {
public:
    KeyPressedEvent(KeyCode keyCode, bool isRepeated = false)
        : KeyEvent(keyCode)
        , isRepeated_(isRepeated)
    {
    }

    bool isRepeated() const { return isRepeated_; }

    EventType getType() const override { return EventType::KeyPressed; }

private:
    bool isRepeated_;
};

class KeyReleasedEvent : public KeyEvent {
public:
    KeyReleasedEvent(KeyCode keyCode)
        : KeyEvent(keyCode)
    {
    }

    EventType getType() const override { return EventType::KeyReleased; }
};

class KeyTypedEvent : public KeyEvent {
public:
    KeyTypedEvent(KeyCode keyCode)
        : KeyEvent(keyCode)
    {
    }

    EventType getType() const override { return EventType::KeyTyped; }
};

}

#endif