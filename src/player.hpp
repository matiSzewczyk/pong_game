#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

#include <SFML/Graphics.hpp>

class Player: public sf::Sprite
{
    private:
        sf::RectangleShape player;
        float speed;
        sf::Vector2f playerPos;

    public:
        sf::FloatRect playerCollision;
        Player(const char &nr, sf::RenderWindow &window);

        void playerMoveUp(float &dT, bool &isPressed);
        void playerMoveDown(float &dT, bool &isPressed, sf::RenderWindow &window);
        void getPlayerPos();
        void drawPlayer(sf::RenderWindow &window);
};
#endif

/*
 *I had to use playerCollision and actively update it because 
 *for some reason getGlobalBounds() always returned 0 within 
 *the ball class
 */
