#pragma once

#include <SFML/Graphics.hpp>

#include "ResourceHolder.hpp"
#include "SceneNode.hpp"

namespace eng {
    class LevelBase :public SceneNode{
    public:
        LevelBase(sf::RenderWindow &window);
        
        void Initialize();
        void HandleInputs() { }
        void HandleEvents() { }
        void Update(float dt);
        void Display();
    private:
        void _pLoadTexture(const std::string& background_filename, const std::string& collision_filename, const std::string& foreground_collision);
        
        Resources::ResourceHolder _mResourceHolder;
        
        sf::RenderWindow* _mWindow;
        
        sf::Sprite _mBackgroundLayer;
        sf::Sprite _mCollisionLayer;
        sf::Sprite _mForegroundLayer;
    };
}
