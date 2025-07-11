#include "Application.hpp"
#include "AbstractWindow.hpp"
#include "Log.hpp"

#include <cstdlib>
#include <stdexcept>
namespace Solid {

Application::Application()
{
    try {
        window_ = AbstractWindow::create({ "Solid Engine", 1280, 1920 });
    } catch (const std::runtime_error& e) {
        SOLID_CORE_ERROR("Application initialization failed: {}", e.what());
        std::exit(EXIT_FAILURE);
    }
}

Application::~Application()
{
}

void Application::run()
{
    window_->onUpdate();
}

}
