#pragma once

#include "../Util/Window.hpp"

#include <SFML/Graphics.hpp>

#include <Box2D/Box2D.h>

#include "../../SceneNode.hpp"
#include "../Resources/ResourceHolder.hpp"

namespace eng {
    class EntityBase :public SceneNode{
    public:
        EntityBase();
        
        virtual void SetRotation(const float angle);
        virtual float GetRotation();
        
        virtual void SetPosition(const sf::Vector2f& pos);
        virtual void AddToPosition(const sf::Vector2f& add_pos);
        virtual sf::Vector2f GetPosition();
        
        virtual void SetScale(sf::Vector2f& scale);
        virtual void SetScale(float x, float y);
        virtual sf::Vector2f GetScale();
        
        virtual void SetVelocity(const sf::Vector2f& new_velocity);
        virtual void AddToVelocity(const sf::Vector2f& add_velocity);
        virtual sf::Vector2f GetVelocity();
        
        virtual void SetAcceleration(const sf::Vector2f& new_acceleration);
        virtual sf::Vector2f GetAcceleration();
        
        void Initialize(b2World& world);
        void HandleInputs();
        void HandleEvents();
        void Update();
        void Display();
    protected:
        Resources::ResourceHolder _mResourceHolder;
        
        sf::Sprite _mSprite; //Object with texture
        
        sf::Vector2f _mVelocity; //Velocity of an object;
        sf::Vector2f _mAcceleration; //Acceleration of an entity
        
        sf::Vector2f _mScale;
        
        float _mGravitation;
        virtual void _pCenterSpriteOrigin();
        virtual void _pLoadTexture(const std::string& filename);
    };
}
