#include "ball.hpp"

Ball::Ball()
{
    ball.setRadius(20.f);
    ball.setPosition(sf::Vector2f(100.f, 500.f));
    ball.setFillColor(sf::Color::Green);

    speed = 600.f;
    ballAngle = 75.f;
}

void Ball::ballMovement(float &dT)
{
    factor = dT * speed;
    velocity.x = std::cos(ballAngle)*factor;
    velocity.y = std::sin(ballAngle)*factor;
    ball.move(velocity.x, velocity.y);
}

void Ball::checkColision(Player *playerOne, Player *playerTwo)
{
    if (ball.getGlobalBounds().intersects(playerOne->getGlobalBounds()) ||
        ball.getGlobalBounds().intersects(playerTwo->getGlobalBounds())) {
        std::cout << "kolizja";
        speed = -speed;
        velocity.x = -(velocity.x);
        ballAngle = -ballAngle;
    }
    if (ball.getGlobalBounds().top <= 0 || ball.getGlobalBounds().height >= 1080) {
        velocity.x = -velocity.x;
        ballAngle = -ballAngle;
    }
    std::cout << "Ball: " << ball.getGlobalBounds().left << std::endl;
    std::cout << "Player: " << playerTwo->getGlobalBounds().left << std::endl;
}

void Ball::drawBall(sf::RenderWindow &window)
{
    window.draw(ball);
}

void Ball::getBallPosition()
{
    ballPos = ball.getPosition();
}
