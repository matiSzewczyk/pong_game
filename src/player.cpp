#include "player.hpp"

Player::Player(const char &nr, sf::RenderWindow &window)
{
    player.setSize(sf::Vector2f(25.f, 150.f));
    if (nr == '1') {
        this->player.setFillColor(sf::Color::Red);
        this->originalPos = sf::Vector2f(25.f, window.getSize().y/2.f - player.getSize().y/2);
        this->player.setPosition(originalPos); 
    } else {
        this->player.setFillColor(sf::Color::Blue);
        this->originalPos = sf::Vector2f(window.getSize().x - player.getSize().x-25,
                                              window.getSize().y/2.f - player.getSize().y/2);
        this->player.setPosition(originalPos); 
    }
    speed = 700.f;
}

void Player::playerMoveUp(float &dT, bool &isPressed)
{
    if (isPressed && this->playerPos.y > 25.f) { //25 is the width of the outer lines
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

void Player::setOriginalPos()
{
    this->player.setPosition(originalPos);
}

void Player::drawPlayer(sf::RenderWindow &window)
{
    window.draw(this->player);
}
