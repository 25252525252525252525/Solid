#include "SandboxApp.hpp"

#include <memory>

int main()
{
    auto engine = std::make_unique<Solid::Engine>();
    engine->run([] { return std::make_unique<Sandbox::SandboxApp>(); });
    return 0;
}
