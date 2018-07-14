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
        Player();
        
        void SetRotation(const float angle);
        float GetRotation();
        
        void SetPosition(const sf::Vector2f& pos);
        void AddToPosition(const sf::Vector2f& add_pos);
        sf::Vector2f GetPosition();
        
        void SetScale(const sf::Vector2f& scale);
        void SetScale(float x, float y);
        sf::Vector2f GetScale();

        void SetMovingMultiplier(int multiplier);
        
        void Initialize(b2World& world);
        void HandleInputs();
        void HandleEvents();
        void Update();
        void Display();
        
        //TEMP
        void Anim();
    private:
        //PRIVATE METHODS//
        void _pLoadTexture(const string& filename, enum Resources::Textures type);
        
        void _pJump();
        
        bool _pIsEntityMoving();
    
        void _pCenterSpriteOrigin();
        
        //PRIVATE VARIABLES//
        Resources::ResourceHolder _mResourceHolder;
        
        sf::Sprite _mSprite;
        
        sf::Vector2f _mPosition;
        sf::Vector2f _mVelocity;
        
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
