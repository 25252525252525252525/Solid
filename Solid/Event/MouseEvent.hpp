#ifndef SOLID_EVENT_MOUSE_EVENT_HPP
#define SOLID_EVENT_MOUSE_EVENT_HPP

#include "Event.hpp"
#include "MouseCode.hpp"

#include <sstream>
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

    EventType getType() const override
    {
        return EventType::MouseButtonPressed;
    }

    std::string getName() const override
    {
        return "MouseButtonPressedEvent";
    }

    std::string toString() const override
    {
        std::stringstream ss;
        ss << "MouseButtonPressedEvent: " << mouseCode_;
        return ss.str();
    }

    static EventType getStaticType()
    {
        return EventType::MouseButtonPressed;
    }
};

class MouseButtonReleasedEvent : public MouseButtonEvent {
public:
    MouseButtonReleasedEvent(MouseCode mouseCode)
        : MouseButtonEvent(mouseCode)
    {
    }

    EventType getType() const override
    {
        return EventType::MouseButtonReleased;
    }

    std::string getName() const override
    {
        return "MouseButtonReleasedEvent";
    }

    std::string toString() const override
    {
        std::stringstream ss;
        ss << "MouseButtonReleasedEvent: " << mouseCode_;
        return ss.str();
    }

    static EventType getStaticType()
    {
        return EventType::MouseButtonReleased;
    }
};

class MouseMovedEvent : public Event {
public:
    MouseMovedEvent(double x, double y)
        : x_(x)
        , y_(y)
    {
    }

    int getCategoryFlags() const override
    {
        return EventCategory::Mouse | EventCategory::Input;
    }

    EventType getType() const override
    {
        return EventType::MouseMoved;
    }

    std::string getName() const override
    {
        return "MouseMovedEvent";
    }

    std::string toString() const override
    {
        std::stringstream ss;
        ss << "MouseMovedEvent: " << x_ << " " << y_;
        return ss.str();
    }

    double getX() const
    {
        return x_;
    }
    double getY() const
    {
        return y_;
    }

    static EventType getStaticType()
    {
        return EventType::MouseMoved;
    }

private:
    double x_;
    double y_;
};

class MouseScrolledEvent : public Event {
public:
    MouseScrolledEvent(double xOffset, double yOffset)
        : xOffset_(xOffset)
        , yOffset_(yOffset)
    {
    }

    int getCategoryFlags() const override
    {
        return EventCategory::Mouse | EventCategory::Input;
    }

    EventType getType() const override
    {
        return EventType::MouseScrolled;
    }

    std::string getName() const override
    {
        return "MouseScrolledEvent";
    }

    std::string toString() const override
    {
        std::stringstream ss;
        ss << "MouseScrolledEvent: " << xOffset_ << " " << yOffset_;
        return ss.str();
    }

    double getXOffset() const
    {
        return xOffset_;
    }
    double getYOffset() const
    {
        return yOffset_;
    }

    static EventType getStaticType()
    {
        return EventType::MouseScrolled;
    }

private:
    double xOffset_;
    double yOffset_;
};

}

#endif
