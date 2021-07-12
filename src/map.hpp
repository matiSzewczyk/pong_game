#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

class Map
{
    private:
        sf::RectangleShape xMapPiece, yMapPiece;
        
    public:
        Map();
        void drawOuterLines(sf::RenderWindow &window);
};
#endif
