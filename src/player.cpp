#include "player.hpp"

Player::Player(const char &nr, sf::RenderWindow &window)
{
    player.setSize(sf::Vector2f(25.f, 150.f));
    if (nr == '1') {
        this->player.setFillColor(sf::Color::Red);
        this->player.setPosition(sf::Vector2f(25.f, window.getSize().y/2.f - player.getSize().y/2)); 
    } else {
        this->player.setFillColor(sf::Color::Blue);
        this->player.setPosition(sf::Vector2f(window.getSize().x - player.getSize().x-25,
                                              window.getSize().y/2.f - player.getSize().y/2)); 
    }
    speed = 700.f;
}

void Player::playerMoveUp(float &dT, bool &isPressed, sf::Vector2f &pos)
{
    if (isPressed && this->playerPos.y > 25.f) {
        this->player.move(0, -speed * dT);
    }
}

void Player::playerMoveDown(float &dT, bool &isPressed, sf::RenderWindow &window)
{
    if (isPressed && this->playerPos.y + this->player.getLocalBounds().height < window.getSize().y - 25.f) {
        this->player.move(0, speed * dT);
    }
}

void Player::getPlayerPos()
{
    this->playerPos = this->player.getPosition();
    this->playerCollision = this->player.getGlobalBounds();
}

void Player::drawPlayer(sf::RenderWindow &window)
{
    window.draw(this->player);
}
