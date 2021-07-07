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

void Player::playerMoveUp(float &dT, bool &isPressed, sf::Vector2f &pos)
{
    if (isPressed && this->playerPos.y > 0) {
        this->player.move(0, -600.f * dT);
    }
}

void Player::playerMoveDown(float &dT, bool &isPressed, sf::RenderWindow &window)
{
    if (isPressed && this->playerPos.y + this->player.getLocalBounds().height < window.getSize().y) {
        this->player.move(0, 600.f * dT);
    }
}

void Player::getPlayerPos()
{
    this->playerPos = this->player.getPosition();
    this->playerCollision = this->player.getGlobalBounds();
}

void Player::drawPlayer(sf::RenderWindow &window)
{
    std::cout << "Player class: " << this->player.getGlobalBounds().left << std::endl;
    window.draw(this->player);
}
