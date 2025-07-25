#ifndef SOLID_PLATFORM_LINUX_WINDOW_HPP
#define SOLID_PLATFORM_LINUX_WINDOW_HPP

#include "AbstractWindow.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

namespace Solid::Platform::Linux {

class Window : public AbstractWindow {
public:
    Window(const WindowProps& windowProps);
    ~Window();

    void onUpdate() override;
    int getHeight() const override;
    int getWidth() const override;
    void setEventCallbackFunction(const EventCallbackFunction& eventCallbackFunction) override;

private:
    void init(const WindowProps& windowProps);
    void shutdown();
    void setGlfwCallbacks();

    struct WindowData {
        std::string title;
        int width;
        int height;
        EventCallbackFunction eventCallbackFunction;
    };

    WindowData windowData_;
    GLFWwindow* window_;

    static unsigned int windowCount_;
};

}

#endif
