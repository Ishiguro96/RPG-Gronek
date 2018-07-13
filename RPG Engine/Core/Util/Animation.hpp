#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
using namespace std;

class Animation{
public:
    void SetAnimationParameters(const sf::Vector2u& size_of_one_frame,
                                const sf::IntRect& array_of_textures,
                                const uint8_t number_of_window_frames_to_next_frame);
    void UpdateAnimationParameter(const sf::IntRect& new_array_of_textures);
    
    void AnimateSprite(sf::Sprite& sprite_to_animate);
    
    void AnimationResume();
    void AnimationStop();
    
    sf::IntRect _array;
private:
    sf::Vector2u _size;
    uint8_t _frames;
    uint16_t _totalFrames;
    uint8_t _frameNumber;
    
    uint16_t _windowFrameCtr;
    
    uint8_t _xCtr;
    uint8_t _yCtr;
    
    bool _animStart;
    bool _asc;
    
    sf::Texture* _animationTexture;
};
