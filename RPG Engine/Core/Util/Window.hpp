#pragma once

#include <SFML/Graphics.hpp>

namespace eng {
    class Window{
    public:
        static sf::RenderWindow& GetWindow();
        
        static void InitWindow();
        
        static void ClearWindow(sf::Color color = sf::Color::Black);
        
        static void HandleEvents();
        
        static void DisplayWindow();
        
        static bool IsWindowOpen();
        
        static void CloseWindow();
        
        static void DrawObject(sf::Drawable drawable);
    private:
        Window() { }
        static sf::RenderWindow _mWindow;
    };
}
