#pragma once

#include "../Util/Window.hpp"

#include <SFML/Graphics.hpp>

#include <Box2D/Box2D.h>

#include "../../ResourcePath.hpp"
#include "../Resources/ResourceHolder.hpp"

#include "../../SceneNode.hpp"

namespace eng {
    class Player :public SceneNode{
    public:
        #pragma mark - Construtors
        Player();
        
        #pragma mark - Initialization
        void Initialize(b2World& world);
        
        #pragma mark - Rotation
        void SetRotation(const float angle);
        float GetRotation();
        
        #pragma mark - Position
        void SetPosition(const sf::Vector2f& pos);
        void AddToPosition(const sf::Vector2f& add_pos);
        sf::Vector2f GetPosition();
        
        #pragma mark - Scale
        void SetScale(const sf::Vector2f& scale);
        void SetScale(float x, float y);
        sf::Vector2f GetScale();
        
        #pragma mark - Handling inputs
        void HandleInputs();
        #pragma mark - Handling game events
        void HandleEvents();
        #pragma mark - Updating
        void Update();
        #pragma mark - Displaying
        void Display();
        
        #pragma make - Temporary methods
        //TEMP
        void Anim(); //Tem
    private:
        #pragma mark - Private methods
        void _pLoadTexture(const string& filename, enum Resources::Textures type);
        
        bool _pIsEntityMoving();
    
        void _pCenterSpriteOrigin();
        
        //PRIVATE VARIABLES//
        Resources::ResourceHolder _mResourceHolder;
        
        sf::Sprite _mSprite;
        
        sf::Vector2f _mPosition;
        sf::Vector2f _mVelocity;
        sf::Vector2f _mMaxVelocity;
        
        sf::Vector2f _mDesiredVelocity;
        
        sf::Vector2f _mScale;
        
        int _moveMultiplier;
        
        bool _mCanJump;
        bool _mJump;
        
        //TEMP
        int frame;
        int ctr;
        bool shouldMove;
        
        //Box2D
        b2BodyDef _mb2BodyDef;
        b2Body* _mb2Body;
        b2PolygonShape _mb2BodyShape;
        b2FixtureDef _mb2BodyFixture;
    };
}
