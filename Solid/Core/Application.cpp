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
    for (const auto& layer : layerStack_) {
        layer->onUpdate();
    }

    window_->onUpdate();
}

void Application::onEvent(Event::Event& event)
{
    SOLID_CORE_TRACE("{}", event.toString());
    Event::EventDispatcher eventDispatcher(event);
    eventDispatcher.dispatch<Event::WindowCloseEvent>(
        SOLID_BIND_EVENT_FUNCTION(Application::onWindowClose));

    for (auto it = layerStack_.rbegin(); it != layerStack_.rend(); ++it) {
        if (event.isHandled_) {
            break;
        }

        (*it)->onEvent(event);
    }
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

void Application::pushLayer(std::shared_ptr<Layer> layer)
{
    layerStack_.pushLayer(layer);
}

void Application::pushOverlay(std::shared_ptr<Layer> layer)
{
    layerStack_.pushOverlay(layer);
}

}
