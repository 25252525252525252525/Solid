#ifndef SOLID_CORE_APPLICATION_HPP
#define SOLID_CORE_APPLICATION_HPP

#include "AbstractWindow.hpp"
#include "ApplicationEvent.hpp"
#include "Event.hpp"

#define SOLID_BIND_EVENT_FUNCTION(fn)                                                              \
    [this](auto&&... args) -> decltype(auto) {                                                     \
        return this->fn(std::forward<decltype(args)>(args)...);                                    \
    }

namespace Solid {

class Application {
public:
    Application();
    virtual ~Application();
    virtual void run();
    void onEvent(Event::Event& event);
    bool isRunning() const;

private:
    bool onWindowClose(Event::WindowCloseEvent& event);

    std::unique_ptr<AbstractWindow> window_;
    bool isRunning_;
};

}

#endif
