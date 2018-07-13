#include "EntityBase.hpp"

namespace eng {
////////////////////////////////////////////////////////////////////////////////////////
//                                ***PUBLIC METHODS***                                //
////////////////////////////////////////////////////////////////////////////////////////

    ///////////////
    //CONSTRUCTOR//
    ///////////////
    EntityBase::EntityBase(){
        _mVelocity.x = 0.0f;
        _mVelocity.y = 0.0f;
        
        _mAcceleration.x = 0;
        _mAcceleration.y = 0;
        
        _mGravitation = 10.0f;
    }

    ////////////////////
    //ROTATION METHODS//
    ////////////////////
    void EntityBase::SetRotation(const float angle){
        _mSprite.rotate(angle);
    }
    
    float EntityBase::GetRotation(){
        return _mSprite.getRotation();
    }

    /////////////////
    //SCALE METHODS//
    /////////////////
    void EntityBase::SetScale(sf::Vector2f& scale){
        SetScale(scale.x, scale.y);
    }

    void EntityBase::SetScale(float x, float y){
        _mSprite.setScale(x, y);
    }

    sf::Vector2f EntityBase::GetScale(){
        return _mSprite.getScale();
    }

    ////////////////////
    //POSITION METHODS//
    ////////////////////
    void EntityBase::SetPosition(const sf::Vector2f& pos){
        _mSprite.setPosition(pos.x, pos.y);
    }

    void EntityBase::AddToPosition(const sf::Vector2f& add_pos){
        _mSprite.setPosition(_mSprite.getPosition().x + add_pos.x, _mSprite.getPosition().y + add_pos.y);
    }
    
    sf::Vector2f EntityBase::GetPosition(){
        return _mSprite.getPosition();
    }

    ////////////////////
    //VELOCITY METHODS//
    ////////////////////
    void EntityBase::SetVelocity(const sf::Vector2f& new_velocity){
        _mVelocity = new_velocity;
    }

    void EntityBase::AddToVelocity(const sf::Vector2f &add_velocity){
        _mVelocity += add_velocity;
    }

    sf::Vector2f EntityBase::GetVelocity(){
        return _mVelocity;
    }

    ////////////////////////
    //ACCELERATION METHODS//
    ////////////////////////
    void EntityBase::SetAcceleration(const sf::Vector2f &new_acceleration){
        _mAcceleration = new_acceleration;
    }

    sf::Vector2f EntityBase::GetAcceleration(){
        return _mAcceleration;
    }

    /////////////////////
    //INITIALIZE METHOD//
    /////////////////////
    void EntityBase::Initialize(b2World& world){
        _pLoadTexture("icon.png");
        
        EntityBase::SetScale(0.25f, 0.25f);
        
        SetPosition(sf::Vector2f(400, 650));
    }

    //////////////////////////////////////
    //HANDLING EVENTS AND INPUTS METHODS//
    //////////////////////////////////////
    void EntityBase::HandleEvents(){
        _pCenterSpriteOrigin();
    }

    void EntityBase::HandleInputs(){
        
    }

    //////////////////////////////
    //UPDATE AND DISPLAY METHODS//
    //////////////////////////////
    void EntityBase::Update(){
        _pCenterSpriteOrigin();
        
        AddToVelocity(_mAcceleration);
        AddToPosition(_mVelocity);
    }

    void EntityBase::Display(){
        Window::GetWindow().draw(_mSprite);
    }


/////////////////////////////////////////////////////////////////////////////////////////
//                                ***PRIVATE METHODS***                                //
/////////////////////////////////////////////////////////////////////////////////////////

    /////////////////////////////////
    //CENTER SPRITE'S ORIGIN METHOD//
    /////////////////////////////////
    void EntityBase::_pCenterSpriteOrigin(){
        _mSprite.setOrigin(_mSprite.getLocalBounds().height/2, _mSprite.getLocalBounds().width/2);
    }

    void EntityBase::_pLoadTexture(const std::string &filename){
        _mResourceHolder.Load(Resources::Textures::TEST_ENTITY, filename);
        _mSprite.setTexture(_mResourceHolder.Get(Resources::Textures::TEST_ENTITY));
    }
}
