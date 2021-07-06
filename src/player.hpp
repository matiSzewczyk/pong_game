#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

#include <SFML/Graphics.hpp>

class Player
{
    private:
        sf::RectangleShape player;


    public:
        Player(const char &nr);
        void playerMovement(float &dT, const char &nr);
        void drawPlayer(sf::RenderWindow &window);
};
#endif
