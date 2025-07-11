#include "Window.hpp"
#include "AbstractWindow.hpp"
#include "Log.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <memory>
#include <stdexcept>

namespace Solid::Platform::Linux {

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
        "Creating a window {} ({}, {})", windowData_.title, windowData_.height, windowData_.width);

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

int Window::getHeight() const
{
    return windowData_.height;
}

int Window::getWidth() const
{
    return windowData_.width;
}

} // namespace Solid::Platform::Linux

namespace Solid {

std::unique_ptr<AbstractWindow> AbstractWindow::create(const WindowProps& windowProps)
{
    return std::make_unique<Platform::Linux::Window>(windowProps);
}

}