#pragma once

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

namespace eng {
    class SceneNode{
    public:
        virtual void Initialize(b2World& world) = 0;
        virtual void HandleInputs() = 0;
        virtual void HandleEvents() = 0;
        virtual void Update() = 0;
        virtual void Display() = 0;
    private:
    };
}
