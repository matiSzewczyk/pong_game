#include "ball.hpp"

Ball::Ball()
{
    ball.setRadius(20.f);
    originalPos = sf::Vector2f(100.f, 500.f);
    ball.setPosition(originalPos);
    ball.setFillColor(sf::Color::White);

    speed = 1400.f;
    ballAngle = 75.f;
}

void Ball::ballMovement(float &dT)
{
    factor = dT * speed;
    velocity.x = std::cos(ballAngle)*factor;
    velocity.y = std::sin(ballAngle)*factor;
    ball.move(velocity.x, velocity.y);
}

void Ball::checkColision(Player *playerOne, Player *playerTwo, sf::RenderWindow &window, int &p1Score, int &p2Score)
{
    // Check if it interacts with the players
    if (ball.getGlobalBounds().intersects(playerOne->playerCollision) ||
        ball.getGlobalBounds().intersects(playerTwo->playerCollision)) {
        speed = -speed;
        velocity.x = -(velocity.x);
        ballAngle = -ballAngle;
    }
    // Check if it goes to the top/bottom of the screen
    if (ball.getGlobalBounds().top <= 0 ||
        ball.getGlobalBounds().top + ball.getGlobalBounds().height >= window.getSize().y) {
        velocity.x = -velocity.x;
        ballAngle = -ballAngle;
    }
    // Check if it reaches one of the two ends (scoring a point)
    if (ball.getGlobalBounds().left < 0) { 
        p2Score++;
        ball.setPosition(originalPos);
        if (speed < 0) speed = -speed;
    }
    if (ball.getGlobalBounds().left + ball.getGlobalBounds().width > window.getSize().x) {
        p1Score++;
        ball.setPosition(originalPos);
        //if (speed < 0) speed = -speed;
    }
}

void Ball::drawBall(sf::RenderWindow &window)
{
    window.draw(ball);
}

void Ball::setOriginalPos()
{
    this->ball.setPosition(originalPos);
}

void Ball::getBallPosition()
{
    ballPos = ball.getPosition();
}
