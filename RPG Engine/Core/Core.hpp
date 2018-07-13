#pragma once

#include "Util/Window.hpp"

#include <memory>
#include <iostream>
#include <stack>

#include "States/StatesHandler.hpp"

#include "States/MainMenuState.hpp"
#include "States/GameState.hpp"

#include <SFML/Graphics.hpp>

namespace eng {
    class Core{
    public:
        Core();
        
        void RunMainLoop();
        
        StatesHandler& GetStates();
    private:
        StatesHandler _mStates;
        
        sf::Clock _mClock;
        sf::Time _mAccumulator = sf::Time::Zero;
        sf::Time _mUpperLimit = sf::seconds(1.0f / 60.0f);
    };
}
