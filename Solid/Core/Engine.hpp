#ifndef SOLID_CORE_ENGINE_HPP
#define SOLID_CORE_ENGINE_HPP

#include "Application.hpp"

#include <functional>
#include <memory>

namespace Solid {

using ApplicationFactory = std::function<std::unique_ptr<Application>()>;

class Engine {
public:
    void run(ApplicationFactory factory);
};

}

#endif
