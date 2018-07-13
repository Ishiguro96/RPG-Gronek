#include "StatesHandler.hpp"

namespace eng{
    void StatesHandler::ChangeState(StatePtr state){
        PopState();
        states.push(std::move(state));
    }
    
    void StatesHandler::PushState(StatePtr state){
        states.push(std::move(state));
    }
    
    void StatesHandler::PopState(){
        if(!states.empty()){
            states.pop();
        }
    }
    
    StatesBase* StatesHandler::GetTopState(){
        return states.top().get();
    }
}
