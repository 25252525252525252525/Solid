#include "Window.hpp"
#include "AbstractWindow.hpp"
#include "ApplicationEvent.hpp"
#include "KeyEvent.hpp"
#include "Log.hpp"
#include "MouseEvent.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <memory>
#include <stdexcept>

namespace Solid::Platform::Linux {

namespace Constant {
    constexpr bool repeatedAction = true;
}

unsigned int Window::windowCount_ = 0;

Window::Window(const WindowProps& windowProps)
    : window_(nullptr)
{
    init(windowProps);
}

void Window::init(const WindowProps& windowProps)
{
    windowData_.title = windowProps.title;
    windowData_.height = windowProps.height;
    windowData_.width = windowProps.width;

    SOLID_CORE_INFO(
        "Creating a window {} ({}, {})", windowData_.title, windowData_.width, windowData_.height);

    if (windowCount_ == 0) {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }

    window_ = glfwCreateWindow(
        windowData_.width, windowData_.height, windowData_.title.c_str(), nullptr, nullptr);

    if (window_ == nullptr) {
        SOLID_CORE_ERROR("Failed to create the window.");
        throw std::runtime_error("Window creation failed.");
    }

    windowCount_++;
    glfwMakeContextCurrent(window_);

    auto status = gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));
    if (!status) {
        SOLID_CORE_ERROR("Failed to initialize GLAD.");
        throw std::runtime_error("OpenGL initialization failed.");
    }

    glfwSetWindowUserPointer(window_, &windowData_);

    setGlfwCallbacks();
}

void Window::setGlfwCallbacks()
{
    glfwSetWindowCloseCallback(window_, [](GLFWwindow* window) {
        WindowData* data = reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
        Solid::Event::WindowCloseEvent event;
        data->eventCallbackFunction(event);
    });

    glfwSetWindowSizeCallback(window_, [](GLFWwindow* window, int width, int height) {
        WindowData* data = reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
        data->width = width;
        data->height = height;
        Solid::Event::WindowResizeEvent event(width, height);
        data->eventCallbackFunction(event);
    });

    glfwSetKeyCallback(
        window_, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
            WindowData* data = reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
            switch (action) {
            case GLFW_PRESS: {
                Solid::Event::KeyPressedEvent event(key);
                data->eventCallbackFunction(event);
                break;
            }
            case GLFW_RELEASE: {
                Solid::Event::KeyReleasedEvent event(key);
                data->eventCallbackFunction(event);
                break;
            }
            case GLFW_REPEAT: {
                Solid::Event::KeyPressedEvent event(key, Constant::repeatedAction);
                data->eventCallbackFunction(event);
                break;
            }
            }
        });

    glfwSetCharCallback(window_, [](GLFWwindow* window, unsigned int codepoint) {
        WindowData* data = reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
        Solid::Event::KeyTypedEvent event(codepoint);
        data->eventCallbackFunction(event);
    });

    glfwSetMouseButtonCallback(window_, [](GLFWwindow* window, int button, int action, int mods) {
        WindowData* data = reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
        switch (action) {
        case GLFW_PRESS: {
            Solid::Event::MouseButtonPressedEvent event(button);
            data->eventCallbackFunction(event);
            break;
        }
        case GLFW_RELEASE: {
            Solid::Event::MouseButtonReleasedEvent event(button);
            data->eventCallbackFunction(event);
            break;
        }
        }
    });

    glfwSetScrollCallback(window_, [](GLFWwindow* window, double xoffset, double yoffset) {
        WindowData* data = reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
        Solid::Event::MouseScrolledEvent event(xoffset, yoffset);
        data->eventCallbackFunction(event);
    });

    glfwSetCursorPosCallback(window_, [](GLFWwindow* window, double xpos, double ypos) {
        WindowData* data = reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
        Solid::Event::MouseMovedEvent event(xpos, ypos);
        data->eventCallbackFunction(event);
    });
}

Window::~Window()
{
    shutdown();
}

void Window::shutdown()
{
    if (window_) {
        glfwDestroyWindow(window_);
        window_ = nullptr;
        windowCount_--;
    }

    if (windowCount_ == 0) {
        glfwTerminate();
    }
}

void Window::onUpdate()
{
    glfwPollEvents();
    glfwSwapBuffers(window_);
}

int Window::getWidth() const
{
    return windowData_.width;
}

int Window::getHeight() const
{
    return windowData_.height;
}

void Window::setEventCallbackFunction(const EventCallbackFunction& eventCallbackFunction)
{
    windowData_.eventCallbackFunction = eventCallbackFunction;
}

}

namespace Solid {

std::unique_ptr<AbstractWindow> AbstractWindow::create(const WindowProps& windowProps)
{
    return std::make_unique<Platform::Linux::Window>(windowProps);
}

}
