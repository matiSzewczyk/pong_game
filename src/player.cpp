#include "player.hpp"

Player::Player(const char &nr)
{
    player.setSize(sf::Vector2f(20.f, 100.f));
    if (nr == '1') {
        this->player.setFillColor(sf::Color::Red);
        this->player.setPosition(sf::Vector2f(0.f, 600.f)); 
    } else {
        this->player.setFillColor(sf::Color::Blue);
        this->player.setPosition(sf::Vector2f(1900.f, 600.f)); 
    }
}

void Player::playerMoveUp(float &dT, bool &isPressed)
{

    if (isPressed) {
        this->player.move(0, -600.f * dT);
    }
}
void Player::playerMoveDown(float &dT, bool &isPressed)
{

    if (isPressed) {
        this->player.move(0, 600.f * dT);
    }
}
void Player::playerMoveLeft(float &dT, bool &isPressed)
{

    if (isPressed) {
        this->player.move(-600.f * dT, 0);
    }
}
void Player::playerMoveRight(float &dT, bool &isPressed)
{

    if (isPressed) {
        this->player.move(600.f * dT, 0);
    }
}

void Player::getPlayerPos()
{
    this->playerPos = this->player.getPosition();
}

void Player::drawPlayer(sf::RenderWindow &window)
{
    window.draw(this->player);
}
