#ifndef SOLID_CORE_ABSTRACT_WINDOW_HPP
#define SOLID_CORE_ABSTRACT_WINDOW_HPP

#include "Event.hpp"

#include <functional>
#include <memory>
#include <string>

namespace Solid {

struct WindowProps {
    std::string title;
    int width;
    int height;

    WindowProps(std::string title, int width, int height)
        : title(title)
        , width(width)
        , height(height)
    {
    }
};

using EventCallbackFunction = std::function<void(Solid::Event::Event&)>;

class AbstractWindow {
public:
    virtual ~AbstractWindow() = default;
    virtual void onUpdate() = 0;
    virtual int getWidth() const = 0;
    virtual int getHeight() const = 0;
    virtual void setEventCallbackFunction(const EventCallbackFunction& eventCallbackFunction) = 0;

    static std::unique_ptr<AbstractWindow> create(const WindowProps& windowProps);
};

}

#endif
