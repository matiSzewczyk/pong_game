#include "map.hpp"

Map::Map()
{
   yMapPiece.setFillColor(sf::Color::White); 
   yMapPiece.setSize(sf::Vector2f(25.f, 150.f));
   xMapPiece.setFillColor(sf::Color::White); 
   xMapPiece.setSize(sf::Vector2f(150.f, 25.f));
}

void Map::drawOuterLines(sf::RenderWindow &window)
{
    int yCount = window.getSize().y / yMapPiece.getSize().y +1;
    /*
     *Two loops are required becuase each iteration operates on the SAME object.
     *Can't place the same object in two different positions.
     */
    // Tiles on Y axis.
    for (int i = 0; i < yCount; i++) {
        yMapPiece.setPosition(sf::Vector2f(0.f, yMapPiece.getSize().y * i));
        window.draw(yMapPiece);
    }
    for (int i = 0; i < yCount; i++) {
        yMapPiece.setPosition(sf::Vector2f(window.getSize().x - yMapPiece.getGlobalBounds().width,
                                          yMapPiece.getSize().y * i));
        window.draw(yMapPiece);
    }
    // Tiles on X axis.
    int xCount = window.getSize().x / xMapPiece.getSize().x +1;
    for (int i = 0; i < xCount; i++) {
        xMapPiece.setPosition(sf::Vector2f(xMapPiece.getSize().x * i, 0.f));
        window.draw(xMapPiece);
    }
    for (int i = 0; i < xCount; i++) {
        xMapPiece.setPosition(sf::Vector2f(xMapPiece.getSize().x * i, window.getSize().y - xMapPiece.getSize().y));
        window.draw(xMapPiece);
    }
}
