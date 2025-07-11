#include "Application.hpp"
#include "AbstractWindow.hpp"
namespace Solid {

Application::Application()
{
    window_ = AbstractWindow::create({ "Solid Engine", 1280, 1920 });
}

Application::~Application()
{
}

void Application::run()
{
    window_->onUpdate();
}

}
