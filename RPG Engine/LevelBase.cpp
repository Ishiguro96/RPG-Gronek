#include "LevelBase.hpp"

namespace eng {
    LevelBase::LevelBase(sf::RenderWindow& window){
        this->_mWindow = &window;
    }

    void LevelBase::Initialize(){
        LevelBase::_pLoadTexture("Layer1.png", "Ziuziu.png", "Layer3.png");
        
        _mCollisionLayer.setTextureRect(sf::IntRect(0, 340, 1500, 220));
        _mCollisionLayer.setScale(0.3f, 0.3f);
        _mCollisionLayer.setPosition(100, _mWindow->getSize().y-220*0.3f);
    }

    void LevelBase::Update(float dt){
        
    }

    void LevelBase::Display(){
        _mWindow->draw(_mBackgroundLayer);
        _mWindow->draw(_mCollisionLayer);
    }

    void LevelBase::_pLoadTexture(const std::string& background_filename, const std::string& collision_filename, const std::string& foreground_collision){

        _mResourceHolder.Load(Resources::Textures::TESTLEVEL_BACKGROUND, background_filename);
        _mResourceHolder.Load(Resources::Textures::TESTLEVEL_COLLISION, collision_filename);
        _mResourceHolder.Load(Resources::Textures::TESTLEVEL_FOREGROUND, foreground_collision);
        
        _mBackgroundLayer.setTexture(_mResourceHolder.Get(Resources::Textures::TESTLEVEL_BACKGROUND));
        _mCollisionLayer.setTexture(_mResourceHolder.Get(Resources::Textures::TESTLEVEL_COLLISION));
        _mForegroundLayer.setTexture(_mResourceHolder.Get(Resources::Textures::TESTLEVEL_FOREGROUND));
    }
}
