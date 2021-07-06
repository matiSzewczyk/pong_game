#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

#include <SFML/Graphics.hpp>

class Player
{
    private:
        sf::RectangleShape player;
        float speed;
        sf::Vector2f playerPos;


    public:
        Player(const char &nr);
        void playerMoveUp(float &dT, bool &isPressed, sf::Vector2f &pos);
        void playerMoveDown(float &dT, bool &isPressed, sf::RenderWindow &window);
        void playerMoveLeft(float &dT, bool &isPressed);
        void playerMoveRight(float &dT, bool &isPressed, sf::RenderWindow &window);

        void getPlayerPos();
        void drawPlayer(sf::RenderWindow &window);
};
#endif
