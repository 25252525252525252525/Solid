#ifndef SOLID_CORE_APPLICATION_HPP
#define SOLID_CORE_APPLICATION_HPP

#include "AbstractWindow.hpp"

namespace Solid {

class Application {
public:
    Application();
    virtual ~Application();
    virtual void run();

private:
    std::unique_ptr<AbstractWindow> window_;
};

}

#endif
