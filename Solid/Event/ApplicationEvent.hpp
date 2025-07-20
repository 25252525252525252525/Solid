#ifndef SOLID_EVENT_APPLICATION_EVENT_HPP
#define SOLID_EVENT_APPLICATION_EVENT_HPP

#include "Event.hpp"

#include <sstream>

namespace Solid::Event {

class WindowCloseEvent : public Event {
public:
    WindowCloseEvent() = default;

    int getCategoryFlags() const override
    {
        return EventCategory::Application;
    }
    EventType getType() const override
    {
        return EventType::WindowClose;
    }

    std::string getName() const override
    {
        return "WindowCloseEvent";
    }

    static EventType getStaticType()
    {
        return EventType::WindowClose;
    }
};

class WindowResizeEvent : public Event {
public:
    WindowResizeEvent(unsigned int width, unsigned int height)
        : width_(width)
        , height_(height)
    {
    }

    int getCategoryFlags() const override
    {
        return EventCategory::Application;
    }

    EventType getType() const override
    {
        return EventType::WindowResize;
    }

    std::string getName() const override
    {
        return "WindowResizeEvent";
    }

    std::string toString() const override
    {
        std::stringstream ss;
        ss << "WindowResizeEvent: " << width_ << " " << height_;
        return ss.str();
    }

    unsigned int getWidth() const
    {
        return width_;
    }

    unsigned int getHeight() const
    {
        return height_;
    }

    static EventType getStaticType()
    {
        return EventType::WindowResize;
    }

private:
    unsigned int width_;
    unsigned int height_;
};

class WindowFocusEvent : public Event {
public:
    WindowFocusEvent() = default;

    int getCategoryFlags() const override
    {
        return EventCategory::Application;
    }

    EventType getType() const override
    {
        return EventType::WindowFocus;
    }

    std::string getName() const override
    {
        return "WindowFocusEvent";
    }

    static EventType getStaticType()
    {
        return EventType::WindowFocus;
    }
};

class WindowLostFocusEvent : public Event {
public:
    WindowLostFocusEvent() = default;

    int getCategoryFlags() const override
    {
        return EventCategory::Application;
    }

    EventType getType() const override
    {
        return EventType::WindowLostFocus;
    }

    std::string getName() const override
    {
        return "WindowLostFocusEvent";
    }

    static EventType getStaticType()
    {
        return EventType::WindowLostFocus;
    }
};

class AppTickEvent : public Event {
public:
    AppTickEvent() = default;

    int getCategoryFlags() const override
    {
        return EventCategory::Application;
    }

    EventType getType() const override
    {
        return EventType::AppTick;
    }

    std::string getName() const override
    {
        return "AppTickEvent";
    }

    static EventType getStaticType()
    {
        return EventType::AppTick;
    }
};

class AppUpdateEvent : public Event {
public:
    AppUpdateEvent() = default;

    int getCategoryFlags() const override
    {
        return EventCategory::Application;
    }

    EventType getType() const override
    {
        return EventType::AppUpdate;
    }

    std::string getName() const override
    {
        return "AppUpdateEvent";
    }

    static EventType getStaticType()
    {
        return EventType::AppUpdate;
    }
};

class AppRenderEvent : public Event {
public:
    AppRenderEvent() = default;

    int getCategoryFlags() const override
    {
        return EventCategory::Application;
    }

    EventType getType() const override
    {
        return EventType::AppRender;
    }

    std::string getName() const override
    {
        return "AppRenderEvent";
    }

    static EventType getStaticType()
    {
        return EventType::AppRender;
    }
};

}

#endif
