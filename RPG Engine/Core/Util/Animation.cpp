#include "Animation.hpp"

/******************************************************************************************
 * \brief Function to get basic parameters of sprite animation.
 *
 * \param   size_of_one_frame                      Size of one frame (eg. (32, 32)).
 * \param   array_of_textures                      Set animation rectangle (eg. 4x3).
 * \param   number_of_window_frames_to_next_frame  Amount of window frames that one animation frame beholds.
 *****************************************************************************************/
void Animation::SetAnimationParameters(const sf::Vector2u& size_of_one_frame,
                                       const sf::IntRect& array_of_textures,
                                       const uint8_t number_of_window_frames_to_next_frame){
    
    this->_size = size_of_one_frame;
    this->_array = array_of_textures;
    this->_frames = number_of_window_frames_to_next_frame;
    this->_totalFrames = array_of_textures.width + array_of_textures.height;
    
    this->_frameNumber = 0;
    
    this->_xCtr = array_of_textures.left;
    this->_yCtr = array_of_textures.top;
    
    _animStart = true;
    
    _asc = true;
}

/******************************************************************************************
 * \brief Function to update given rectangle of texture.
 *
 * \param   new_array_of_textures                   New animation rectangle.
 *****************************************************************************************/
void Animation::UpdateAnimationParameter(const sf::IntRect& new_array_of_textures){
    this->_array = new_array_of_textures;
}

/******************************************************************************************
 * \brief Function to animate given sprite.
 *
 * \param   sprite_to_animate               Sprite to animate.
 *****************************************************************************************/
void Animation::AnimateSprite(sf::Sprite& sprite_to_animate){
    if(_frameNumber >= _frames && _animStart){
        sprite_to_animate.setTextureRect(sf::IntRect( (_xCtr - 1) * _size.x, (_yCtr - 1) * _size.y, _size.x, _size.y));
        
        if(_xCtr >= _array.width){
            _asc = false;
            
            if(_yCtr >= _array.height)
                _yCtr = _array.top;
            else
                _yCtr++;
        }
        else if(_xCtr <= _array.left)
            _asc = true;
        
        
        if(_asc){
            _xCtr++;
        }
        else{
            _xCtr--;
        }
        
        _frameNumber = 0;
    }
    else
        _frameNumber++;
}

/******************************************************************************************
 * \brief Function to resume sprite animation.
 *
 *****************************************************************************************/
void Animation::AnimationResume(){
    _animStart = true;
}

/******************************************************************************************
 * \brief Function to stop sprite animation.
 *
 *****************************************************************************************/
void Animation::AnimationStop(){
    _animStart = false;
}
