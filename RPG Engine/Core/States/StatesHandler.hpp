#pragma once

#include "StatesBase.hpp"

#include <stack>
#include <iostream>
#include <memory>

namespace eng {
    
    typedef std::unique_ptr<StatesBase> StatePtr;
    
    class StatesHandler{
    public:
        StatesHandler(StatePtr) { }
        ~StatesHandler() { }
        
        void ChangeState(StatePtr state);
        void PushState(StatePtr state);
        void PopState();
        
        StatesBase* GetTopState();
        
        bool Empty() { return states.empty(); }
    private:
        std::stack<StatePtr> states;
    };
    
}
