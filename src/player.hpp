#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

class Player
{
    private:
        sf::RectangleShape player;


    public:
        Player();
        void playerMovement();
        void drawPlayer(sf::RenderWindow &window);
};
#endif
