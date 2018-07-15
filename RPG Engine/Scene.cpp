#include "Scene.hpp"

namespace eng{
    Scene::Scene() :_b2World(b2Vec2(0.f, 100.f)){
        PPM = 100.f;
    }
    
    void Scene::AddSceneNode(const int ID, enum SceneNodeTypes types){
        switch(types){
            case PLAYER:{
                auto inserted = _mSceneNodes.insert(std::make_pair(ID, new Player()));
                
                assert(inserted.second);
            } break;
            case TEST_ENTITY:{
                auto inserted = _mSceneNodes.insert(std::make_pair(ID, new EntityBase()));
                
                assert(inserted.second);
            }break;
        }
    }

    std::shared_ptr<SceneNode> &Scene::GetSceneNode(const int ID){
        auto found = _mSceneNodes.find(ID);
        assert(found != _mSceneNodes.end());
        
        return found->second;
    }
    
    void Scene::InitializeWorld(){
        _b2GroundDef.position.Set(500.f, 650.f);
        _b2Ground = _b2World.CreateBody(&_b2GroundDef);
        _b2GroundShape.SetAsBox(800.f / 2.f, 50.f / 2.f);
        _b2Ground->CreateFixture(&_b2GroundShape, 1.0f);
        
        _b2BoxDef.type = b2_dynamicBody;
        _b2BoxDef.position.Set(500.f, 2.f);
        _b2Box = _b2World.CreateBody(&_b2BoxDef);
        _b2BoxShape.SetAsBox(10.f / 2.f, 10.f / 2.f);
        
        _b2BoxFixDef.shape = &_b2BoxShape;
        _b2BoxFixDef.density = 1.0f;
        _b2BoxFixDef.friction = 0.8f;
        _b2BoxFixDef.restitution = 0.4f;
        
        _b2Box->CreateFixture(&_b2BoxFixDef);
        
        _b2Box->SetAngularVelocity(2.f);
        //_b2Box->SetTransform(_b2Box->GetPosition(), 60.f * M_PI / 180.f);
        
        _mGround.setSize(sf::Vector2f(800.f, 50.f));
        _mGround.setFillColor(sf::Color::Green);
        _mGround.setOrigin(_mGround.getLocalBounds().width / 2.f, _mGround.getLocalBounds().height / 2.f);
        
        _mBox.setSize(sf::Vector2f(10.f, 10.f));
        _mBox.setFillColor(sf::Color::Cyan);
        _mBox.setOrigin(_mBox.getLocalBounds().width / 2.f, _mBox.getLocalBounds().height / 2.f);
    }
    
    void Scene::WorldLoop(){
        _b2World.Step(1.f/30.f, 8, 3);
        
        _mBox.setPosition(_b2Box->GetPosition().x, _b2Box->GetPosition().y);
        _mBox.setRotation(_b2Box->GetTransform().q.GetAngle() * 180.f / M_PI);
        
        _mGround.setPosition(_b2Ground->GetPosition().x, _b2Ground->GetPosition().y);
        _mGround.setRotation(_b2Ground->GetTransform().q.GetAngle() * 180.f / M_PI);
    }

    void Scene::InitializeSceneNodes(){
        for(auto const &node : _mSceneNodes){
            node.second->Initialize(_b2World);
        }
    }
    
    void Scene::ClearScene(sf::Color color){
        Window::ClearWindow(color);
    }

    void Scene::HandleSceneNodesInputs(){
        for(auto const &node : _mSceneNodes){
            node.second->HandleInputs();
        }
    }

    void Scene::HandleSceneNodesEvents(){
        for(auto const &node : _mSceneNodes){
            node.second->HandleEvents();
        }
    }
    
    void Scene::UpdateScene(){
        for(auto const &node : _mSceneNodes){
            node.second->Update();
        }
    }

    void Scene::DisplayScene(){
        for(auto const &node : _mSceneNodes){
            node.second->Display();
        }
        
        Window::GetWindow().draw(_mBox);
        Window::GetWindow().draw(_mGround);
    }
}
