#include "ball.hpp"

Ball::Ball()
{
    ball.setRadius(20.f);
    ball.setPosition(sf::Vector2f(100.f, 500.f));
    ball.setFillColor(sf::Color::White);

    speed = 800.f;
    ballAngle = 75.f;
}

void Ball::ballMovement(float &dT)
{
    factor = dT * speed;
    velocity.x = std::cos(ballAngle)*factor;
    velocity.y = std::sin(ballAngle)*factor;
    ball.move(velocity.x, velocity.y);
}

void Ball::checkColision(Player *playerOne, Player *playerTwo, sf::RenderWindow &window)
{
    if (ball.getGlobalBounds().intersects(playerOne->playerCollision) ||
        ball.getGlobalBounds().intersects(playerTwo->playerCollision)) {
        speed = -speed;
        velocity.x = -(velocity.x);
        ballAngle = -ballAngle;
    }
    if (ball.getGlobalBounds().top <= 0 ||
        ball.getGlobalBounds().top + ball.getGlobalBounds().height >= window.getSize().y) {
        velocity.x = -velocity.x;
        ballAngle = -ballAngle;
    }
}

void Ball::drawBall(sf::RenderWindow &window)
{
    window.draw(ball);
}

void Ball::getBallPosition()
{
    ballPos = ball.getPosition();
}
