#ifndef SOLID_EVENT_MOUSE_EVENT_HPP
#define SOLID_EVENT_MOUSE_EVENT_HPP

#include "Event.hpp"
#include "MouseCode.hpp"

namespace Solid::Event {

class MouseButtonEvent : public Event {
public:
    int getCategoryFlags() const override
    {
        return EventCategory::Mouse | EventCategory::Input | EventCategory::MouseButton;
    }

protected:
    MouseButtonEvent(MouseCode mouseCode)
        : mouseCode_(mouseCode)
    {
    }

    MouseCode mouseCode_;
};

class MouseButtonPressedEvent : public MouseButtonEvent {
public:
    MouseButtonPressedEvent(MouseCode mouseCode)
        : MouseButtonEvent(mouseCode)
    {
    }

    EventType getType() const override { return EventType::MouseButtonPressed; }

    static EventType getStaticType() { return EventType::MouseButtonPressed; }
};

class MouseButtonReleasedEvent : public MouseButtonEvent {
public:
    MouseButtonReleasedEvent(MouseCode mouseCode)
        : MouseButtonEvent(mouseCode)
    {
    }

    EventType getType() const override { return EventType::MouseButtonReleased; }

    static EventType getStaticType() { return EventType::MouseButtonReleased; }
};

class MouseMovedEvent : public Event {
public:
    MouseMovedEvent(int x, int y)
        : x_(x)
        , y_(y)
    {
    }

    int getCategoryFlags() const override { return EventCategory::Mouse | EventCategory::Input; }

    EventType getType() const override { return EventType::MouseMoved; }

    int getX() const { return x_; }
    int getY() const { return y_; }

    static EventType getStaticType() { return EventType::MouseMoved; }

private:
    int x_;
    int y_;
};

class MouseScrolledEvent : public Event {
public:
    MouseScrolledEvent(float xOffset, float yOffset)
        : xOffset_(xOffset)
        , yOffset_(yOffset)
    {
    }

    int getCategoryFlags() const override { return EventCategory::Mouse | EventCategory::Input; }

    EventType getType() const override { return EventType::MouseScrolled; }

    float getXOffset() const { return xOffset_; }
    float getYOffset() const { return yOffset_; }

    static EventType getStaticType() { return EventType::MouseScrolled; }

private:
    float xOffset_;
    float yOffset_;
};

}

#endif