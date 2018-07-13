#include "GameState.hpp"

namespace eng{
    GameState::GameState(){
        _mScene.AddSceneNode(1, SceneNodeTypes::PLAYER);
        //_mScene.AddSceneNode(1, SceneNodeTypes::TEST_ENTITY, _mCore->GetWindowCore().GetWindow());
        _mScene.InitializeSceneNodes();
        
        _mScene.InitializeWorld();
    }
    
    void GameState::Clear(){
        _mScene.ClearScene(sf::Color::Yellow);
    }
    
    void GameState::HandleEvent(){
        _mScene.HandleSceneNodesEvents();
    }
    
    void GameState::HandleInput(){
        _mScene.HandleSceneNodesInputs();
    }
    
    void GameState::Update(){
        _mScene.UpdateScene();
        
        _mScene.WorldLoop();
    }
    
    void GameState::Render(){
        _mScene.DisplayScene();
    }
}
