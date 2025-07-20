#include "Application.hpp"
#include "AbstractWindow.hpp"
#include "ApplicationEvent.hpp"
#include "Event.hpp"
#include "EventDispatcher.hpp"
#include "Log.hpp"

#include <cstdlib>
#include <stdexcept>

namespace Solid {

Application::Application()
    : isRunning_(true)
{
    try {
        window_ = AbstractWindow::create({ "Solid Engine", 1920, 1280 });
        window_->setEventCallbackFunction(SOLID_BIND_EVENT_FUNCTION(Application::onEvent));
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

void Application::onEvent(Event::Event& event)
{
    SOLID_CORE_TRACE("{}", event.toString());
    Event::EventDispatcher eventDispatcher(event);
    eventDispatcher.dispatch<Event::WindowCloseEvent>(
        SOLID_BIND_EVENT_FUNCTION(Application::onWindowClose));
}

bool Application::onWindowClose(Event::WindowCloseEvent& event)
{
    isRunning_ = false;
    return true;
}

bool Application::isRunning() const
{
    return isRunning_;
}

}
