#ifndef SOLID_EVENT_APPLICATION_EVENT_HPP
#define SOLID_EVENT_APPLICATION_EVENT_HPP

#include "Event.hpp"

namespace Solid::Event {

class WindowCloseEvent : public Event {
public:
    WindowCloseEvent() = default;

    int getCategoryFlags() const override { return EventCategory::Application; }

    EventType getType() const override { return EventType::WindowClose; }

    static EventType getStaticType() { return EventType::WindowClose; }
};

class WindowResizeEvent : public Event {
public:
    WindowResizeEvent(unsigned int width, unsigned int height)
        : width_(width)
        , height_(height)
    {
    }

    int getCategoryFlags() const override { return EventCategory::Application; }

    EventType getType() const override { return EventType::WindowResize; }

    unsigned int getWidth() const { return width_; }
    unsigned int getHeight() const { return height_; }

    static EventType getStaticType() { return EventType::WindowResize; }

private:
    unsigned int width_;
    unsigned int height_;
};

class WindowFocusEvent : public Event {
public:
    WindowFocusEvent() = default;

    int getCategoryFlags() const override { return EventCategory::Application; }

    EventType getType() const override { return EventType::WindowFocus; }

    static EventType getStaticType() { return EventType::WindowFocus; }
};

class WindowLostFocusEvent : public Event {
public:
    WindowLostFocusEvent() = default;

    int getCategoryFlags() const override { return EventCategory::Application; }

    EventType getType() const override { return EventType::WindowLostFocus; }

    static EventType getStaticType() { return EventType::WindowLostFocus; }
};

class AppTickEvent : public Event {
public:
    AppTickEvent() = default;

    int getCategoryFlags() const override { return EventCategory::Application; }

    EventType getType() const override { return EventType::AppTick; }

    static EventType getStaticType() { return EventType::AppTick; }
};

class AppUpdateEvent : public Event {
public:
    AppUpdateEvent() = default;

    int getCategoryFlags() const override { return EventCategory::Application; }

    EventType getType() const override { return EventType::AppUpdate; }

    static EventType getStaticType() { return EventType::AppUpdate; }
};

class AppRenderEvent : public Event {
public:
    AppRenderEvent() = default;

    int getCategoryFlags() const override { return EventCategory::Application; }

    EventType getType() const override { return EventType::AppRender; }

    static EventType getStaticType() { return EventType::AppRender; }
};

}

#endif