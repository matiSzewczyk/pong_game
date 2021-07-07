#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>
#include "player.hpp"
#include <cmath>

class Ball
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
        void checkColision(Player *playerOne, Player *playerTwo, sf::RenderWindow &window, int &p1Score, int &p2Score);
        void drawBall(sf::RenderWindow &window);
        void getBallPosition();
};
#endif
