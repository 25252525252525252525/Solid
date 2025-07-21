#ifndef SANDBOX_SANDBOX_APP_HPP
#define SANDBOX_SANDBOX_APP_HPP

#include "Solid.hpp"

#include <memory>

namespace Sandbox {

class ExampleLayer : public Solid::Layer {
public:
    void onAttach() override
    {
    }
    void onDetach() override
    {
    }

    void onUpdate() override
    {
        SOLID_TRACE("ExampleLayer: update");
    }

    void onEvent(Solid::Event::Event& event) override
    {
        SOLID_TRACE("{}", event.toString());
    }
};

class SandboxApp : public Solid::Application {
public:
    SandboxApp()
    {
        pushLayer(std::make_shared<ExampleLayer>());
    }
};

}

#endif
