#include "Engine.hpp"

namespace Solid {

void Engine::run(ApplicationFactory factory)
{
    auto app = factory();
    while (app->isRunning()) {
        app->run();
    }
}

}
