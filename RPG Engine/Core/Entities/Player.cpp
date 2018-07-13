#include "Player.hpp"
namespace eng {
    ////////////////////////////////////////////////////////////////////////////////////////
    //                                ***PUBLIC METHODS***                                //
    ////////////////////////////////////////////////////////////////////////////////////////

    ///////////////
    //CONSTRUCTOR//
    ///////////////
    Player::Player(){
        _mPosition.x = 500.f;
        _mPosition.y = 0.f;
        
        _mVelocity.x = 0.f;
        _mVelocity.y = 0.f;
        
        _mScale.x = 0.25f;
        _mScale.y = 0.25f;
        Player::SetScale(_mScale);
        
        _moveMultiplier = 4.f;
        
        _mCanJump = false;
        
        //TEMP
        frame = 0;
        ctr = 0;
        shouldMove = false;
    }

    /////////////////////
    //INITIALIZE METHOD//
    /////////////////////
    void Player::Initialize(b2World& world){
        Player::_pLoadTexture("walk40.png");
        
        Player::SetPosition(sf::Vector2f(200.f, 0.f));
        
        _pCenterSpriteOrigin();
        
        //Box2D
        _mb2BodyDef.type = b2_dynamicBody;
        _mb2BodyDef.position.Set(_mPosition.x, _mPosition.y);
        _mb2Body = world.CreateBody(&_mb2BodyDef);
        _mb2BodyShape.SetAsBox(201.f * _mScale.x / 2.f, 369.f * _mScale.y / 2.f);
        
        _mb2BodyFixture.shape = &_mb2BodyShape;
        _mb2BodyFixture.density = 1.0f;
        _mb2BodyFixture.friction = 0.8f;
        _mb2BodyFixture.restitution = 0.f;
        
        _mb2Body->CreateFixture(&_mb2BodyFixture);
    }

    ////////////////////
    //ROTATION METHODS//
    ////////////////////
    void Player::SetRotation(const float angle){
        _mSprite.rotate(angle);
    }

    float Player::GetRotation(){
        return _mSprite.getRotation();
    }

    ////////////////////
    //POSITION METHODS//
    ////////////////////
    void Player::SetPosition(const sf::Vector2f& pos){
        _mSprite.setPosition(pos.x, pos.y);
    }

    void Player::AddToPosition(const sf::Vector2f& add_pos){
        _mSprite.setPosition(_mSprite.getPosition().x + add_pos.x, _mSprite.getPosition().y + add_pos.y);
    }

    sf::Vector2f Player::GetPosition(){
        return _mSprite.getPosition();
    }

    /////////////////
    //SCALE METHODS//
    /////////////////
    void Player::SetScale(const sf::Vector2f& scale){
        SetScale(scale.x, scale.y);
    }

    void Player::SetScale(float x, float y){
        _mSprite.setScale(x, y);
    }

    sf::Vector2f Player::GetScale(){
        return _mSprite.getScale();
    }

    ////////////////////////////
    //MOVING MULTIPLIER METHOD//
    ////////////////////////////
    void Player::SetMovingMultiplier(int multiplier){
        _moveMultiplier = multiplier;
    }

    //////////////////////////////////////
    //HANDLING EVENTS AND INPUTS METHODS//
    //////////////////////////////////////
    void Player::HandleInputs(){
        sf::Keyboard::Key _left = sf::Keyboard::A;
        sf::Keyboard::Key _right = sf::Keyboard::D;
        sf::Keyboard::Key _jump = sf::Keyboard::Space;
        
        if((!sf::Keyboard::isKeyPressed(_left) && !sf::Keyboard::isKeyPressed(_right)) ||
           (sf::Keyboard::isKeyPressed(_left) && sf::Keyboard::isKeyPressed(_right))){
            
        }
        
        else if(sf::Keyboard::isKeyPressed(_left) && !sf::Keyboard::isKeyPressed(_right)){
            _mb2Body->ApplyForceToCenter(b2Vec2(-100.f, -100.f), true);
            _mSprite.setScale(-_mScale.x, _mScale.y);
        }
        else if(sf::Keyboard::isKeyPressed(_right) && !sf::Keyboard::isKeyPressed(_left)){
            _mb2Body->ApplyForceToCenter(b2Vec2(100.f, 100.f), true);
            _mSprite.setScale(_mScale.x, _mScale.y);
        }
        
        if(sf::Keyboard::isKeyPressed(_jump) && _mCanJump){
            _mb2Body->ApplyForceToCenter(b2Vec2(0.f, -10.f), true);
            _mJump = true;
            _mCanJump = false;
        }
    }

    void Player::HandleEvents(){
        
    }

    /////////////////
    //UPDATE METHOD//
    /////////////////
    void Player::Update(){
        //TEMP
        Anim();
        
        _pCenterSpriteOrigin();
        
        _mSprite.setPosition(_mb2Body->GetPosition().x, _mb2Body->GetPosition().y);
        _mSprite.setRotation(_mb2Body->GetAngle() * 180.f / M_PI);
    }

    //////////////////
    //DISPLAY METHOD//
    //////////////////
    void Player::Display(){
        Window::GetWindow().draw(_mSprite);
    }

    /////////////////////////////////////////////////////////////////////////////////////////
    //                                ***PRIVATE METHODS***                                //
    /////////////////////////////////////////////////////////////////////////////////////////
    void Player::_pLoadTexture(const string& filename){
        _mResourceHolder.Load(Resources::Textures::PLAYER, filename);
        _mSprite.setTexture(_mResourceHolder.Get(Resources::Textures::PLAYER));
        _mSprite.setTextureRect(sf::IntRect(0, 0, 201, 369));
    }

    void Player::_pCenterSpriteOrigin(){
        _mSprite.setOrigin(_mSprite.getLocalBounds().width/2, _mSprite.getLocalBounds().height/2);
    }

    void Player::_pJump(){
        _mVelocity.y -= 25.0f;
    }

    bool Player::_pIsEntityMoving(){
        if(_mVelocity.x == 0.0f && _mVelocity.y == 0.0f)
            return false;
        else
            return true;
    }
    
    //TEMP
    void Player::Anim(){
        if(frame >= 1){
            frame = 0;
            if(ctr < 39)
                ++ctr;
            else
                ctr = 0;
        }
        else if (!shouldMove && ctr != 0)
            ++frame;
        else if (shouldMove)
            ++frame;
        
        if(_mVelocity.x != 0)
            shouldMove = true;
        else
            shouldMove = false;
        
        _mSprite.setTextureRect(sf::IntRect(ctr*201, 0, 201, 369));
    }
}
