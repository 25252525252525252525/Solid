#ifndef SOLID_CORE_APPLICATION_HPP
#define SOLID_CORE_APPLICATION_HPP

namespace Solid {

class Application {
public:
    Application() = default;
    virtual ~Application();
    virtual void run();
};

}

#endif
