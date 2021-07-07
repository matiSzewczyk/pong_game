#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>
#include "player.hpp"
#include <cmath>

class Ball: public sf::RectangleShape
{
    private:
        sf::CircleShape ball;
        sf::Vector2f ballPos;
        float speed;
        float factor;
        float ballAngle;
        sf::Vector2f velocity;

    public:
        Ball();
        void ballMovement(float &dT);
        void checkColision(Player *playerOne, Player *playerTwo);
        void drawBall(sf::RenderWindow &window);
        void getBallPosition();
};
#endif
