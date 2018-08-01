#include "Player.hpp"

namespace eng {
    
    #pragma mark - Construtors
    /*!
     @brief Default constructor from Player class.
     */
    Player::Player(){
        _mPosition.x = 500.f;
        _mPosition.y = 0.f;
        
        _mVelocity.x = 0.f;
        _mVelocity.y = 0.f;
        
        _mMaxVelocity.x = 200.f;
        _mMaxVelocity.y = 1000.f;
        
        _mDesiredVelocity.x = 0.f;
        _mDesiredVelocity.y = 0.f;
        
        _mScale.x = 0.5f;
        _mScale.y = 0.5f;
        Player::SetScale(_mScale);
        
        _moveMultiplier = 4.f;
        
        _mCanJump = false;
        
        //TEMP
        frame = 0;
        ctr = 0;
        shouldMove = false;
    }

    #pragma mark - Initialization
    /*!
     @brief Method to initialize Box2D bodies, SFML sprites, etc.
     
     @param world Box2D world in which we create bodies.
     */
    void Player::Initialize(b2World& world){
        Player::_pLoadTexture("idle60.png", Resources::Textures::PLAYER_IDLE);
        Player::_pLoadTexture("walk50.png", Resources::Textures::PLAYER_MOVEMENT);
        _mSprite.setTexture(_mResourceHolder.Get(Resources::Textures::PLAYER_IDLE));
        
        _pCenterSpriteOrigin();
        
        //Box2D
        _mb2BodyDef.type = b2_dynamicBody;
        _mb2BodyDef.position.Set(_mPosition.x / PPM, _mPosition.y / PPM);
        _mb2Body = world.CreateBody(&_mb2BodyDef);
        _mb2BodyShape.SetAsBox((157.f * _mScale.x / 2.f) / PPM,
                               (244.f * _mScale.y / 2.f) / PPM);
        
        _mb2BodyFixture.shape = &_mb2BodyShape;
        _mb2BodyFixture.density = 1.f;
        _mb2BodyFixture.friction = 0.7f;
        _mb2BodyFixture.restitution = 0.f;
        
        _mb2Body->CreateFixture(&_mb2BodyFixture);
        
    }
    
    #pragma mark - Rotation
    /*!
     @brief Method to set SFML sprite rotation.
     
     @param angle Angle to SFML sprite (degreeses, clockwise).
     */
    void Player::SetRotation(const float angle){
        _mSprite.rotate(angle);
    }
    
    /*!
     @brief Method to get rotation of SFML sprite.
     
     @return float Angle of SFML sprite (degreeses, clockwise).
     */
    float Player::GetRotation(){
        return _mSprite.getRotation();
    }

    #pragma mark - Position
    /*!
     @brief Method to set position of SFML sprite.
     
     @param pos Vector with new position.
     */
    void Player::SetPosition(const sf::Vector2f& pos){
        _mSprite.setPosition(pos.x, pos.y);
    }
    
    /*!
     @brief Method to add a vector to a current position of SFML sprite.
     
     @param add_pos Vector with position to be added.
     */
    void Player::AddToPosition(const sf::Vector2f& add_pos){
        _mSprite.setPosition(_mSprite.getPosition().x + add_pos.x, _mSprite.getPosition().y + add_pos.y);
    }

    /*!
     @brief Method to get a SFML sprite position.
     
     @return sf::Vector2f Vector with position of SFML sprite.
     */
    sf::Vector2f Player::GetPosition(){
        return _mSprite.getPosition();
    }

    #pragma mark - Scale
    /*!
     @brief Method to set a SFML sprite scale.
     
     @param scale Vector with new scale.
     */
    void Player::SetScale(const sf::Vector2f& scale){
        SetScale(scale.x, scale.y);
    }

    /*!
     @brief Method to set a SFML sprite scale.
     
     @param x Scale on x-axis.
     @param y Scale on y-axis.
     */
    void Player::SetScale(const float x, const float y){
        _mSprite.setScale(x, y);
    }
    
    /*!
     @brief Method to get SFML sprite scale.
     
     @return sf::Vector2f Vector with scale.
     */
    sf::Vector2f Player::GetScale(){
        return _mSprite.getScale();
    }

    #pragma mark - Handling inputs
    /*!
     @brief Method to handle inputs (keyboard, mouse, etc.).
     */
    void Player::HandleInputs(){
        sf::Keyboard::Key _left = sf::Keyboard::A;
        sf::Keyboard::Key _right = sf::Keyboard::D;
        
        if((!sf::Keyboard::isKeyPressed(_left) && !sf::Keyboard::isKeyPressed(_right)) ||
           (sf::Keyboard::isKeyPressed(_left) && sf::Keyboard::isKeyPressed(_right)))
        {
            
        }
        if(sf::Keyboard::isKeyPressed(_left) && !sf::Keyboard::isKeyPressed(_right)){
            _mSprite.setScale(-_mScale.x, _mScale.y);
        }
        else if(sf::Keyboard::isKeyPressed(_right) && !sf::Keyboard::isKeyPressed(_left)){
            _mSprite.setScale(_mScale.x, _mScale.y);
        }
    }
    
    #pragma mark - Handling game events
    /*!
     @brief *WIP* Method to handle game events.
     */
    void Player::HandleEvents(){
        
    }
    
    #pragma mark - Updating
    /*!
     @brief Method do update player phycics, logic and rendering.
     */
    void Player::Update(){
        Anim(); //Temporary animation method
        
        if(_mb2Body->GetLinearVelocity().y == 0.f){
            _mCanJump = true;
        }
        
        _mb2Body->SetFixedRotation(true);
        
        _mVelocity.x = _mb2Body->GetLinearVelocity().x;
        _mVelocity.y = _mb2Body->GetLinearVelocity().y;
        
        _pCenterSpriteOrigin();
        
        _mSprite.setPosition(_mb2Body->GetPosition().x * PPM, _mb2Body->GetPosition().y * PPM);
        _mSprite.setRotation(_mb2Body->GetAngle() * 180.f / M_PI);
    }

    #pragma mark - Displaying
    /*!
     @brief Method to render player SFML stuff.
     */
    void Player::Display(){
        Window::GetWindow().draw(_mSprite);
    }

    #pragma mark - Private methods
    /*!
     @brief Private method to load texture to Resource Holder.
     */
    void Player::_pLoadTexture(const string& filename, enum Resources::Textures type){
        _mResourceHolder.Load(type, filename);
    }
    
    /*!
     @brief Private method to center SFML sprite origin.
     */
    void Player::_pCenterSpriteOrigin(){
        _mSprite.setOrigin(_mSprite.getLocalBounds().width / 2.f,
                           _mSprite.getLocalBounds().height / 2.f);
    }
    
    /*!
     @brief *WIP* Checks if the entity is moving.
     
     @return bool True/false depending if the entity is moving.
     */
    bool Player::_pIsEntityMoving(){
        if(_mVelocity.x == 0.0f && _mVelocity.y == 0.0f)
            return false;
        else
            return true;
    }
    
    ///Temporary sprite animation class. */
    void Player::Anim(){
        if(frame >= 1){
            frame = 0;
            if(shouldMove){
                if(ctr < 49)
                    ++ctr;
                else
                    ctr = 0;
            }
            else{
                if(ctr < 59)
                    ++ctr;
                else
                    ctr = 0;
                }
        }
        frame++;
        
        if(_mVelocity.x < -0.01f || _mVelocity.x > 0.01f)
            shouldMove = true;
        else
            shouldMove = false;
        
        if(shouldMove){
            _mSprite.setTexture(_mResourceHolder.Get(Resources::Textures::PLAYER_MOVEMENT));
            _mSprite.setTextureRect(sf::IntRect(ctr * 157.f, 0.f, 157.f, 244.f));
        }
        else{
            _mSprite.setTexture(_mResourceHolder.Get(Resources::Textures::PLAYER_IDLE));
            _mSprite.setTextureRect(sf::IntRect(ctr * 129.f, 0.f, 129.f, 235.f));
        }
    }
}
