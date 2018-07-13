#include "Core.hpp"

namespace eng{
    Core::Core() :_mStates(NULL){
        Window::InitWindow();
        _mStates.ChangeState(std::make_unique<GameState>());
    }

    void Core::RunMainLoop(){
        while(Window::IsWindowOpen()){
            if(!_mStates.Empty()){
                _mStates.GetTopState()->Clear();
                
                Window::HandleEvents();
                
                _mStates.GetTopState()->HandleEvent();
                _mStates.GetTopState()->HandleInput();
                
                while(_mAccumulator > _mUpperLimit){ //Run the logic at 60FPS
                    _mAccumulator -= _mUpperLimit;
                    
                    _mStates.GetTopState()->Update();
                }
                _mStates.GetTopState()->Render();
                
                Window::DisplayWindow();
                
                _mAccumulator += _mClock.restart();
            }
            else{
                Window::CloseWindow();
                break;
            }
        }
    }
}
