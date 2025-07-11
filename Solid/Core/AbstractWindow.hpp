#ifndef SOLID_CORE_ABSTRACT_WINDOW_HPP
#define SOLID_CORE_ABSTRACT_WINDOW_HPP

#include <memory>
#include <string>

namespace Solid {

struct WindowProps {
    std::string title;
    int height;
    int width;

    WindowProps(std::string title, int height, int width)
        : title(title)
        , height(height)
        , width(width)
    {
    }
};

class AbstractWindow {
public:
    virtual ~AbstractWindow() = default;
    virtual void onUpdate() = 0;
    virtual int getHeight() const = 0;
    virtual int getWidth() const = 0;

    static std::unique_ptr<AbstractWindow> create(const WindowProps& windowProps);
};

}

#endif