#pragma once

#include "StatesBase.hpp"

#include "../Util/Window.hpp"

namespace eng {
    class Core;
    
    class MainMenuState :public StatesBase{
    public:
        MainMenuState();
        
        void Clear();
        void HandleEvent();
        void HandleInput();
        void Update();
        void Render();
    private:
    };
}
