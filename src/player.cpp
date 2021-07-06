#include "player.hpp"

Player::Player()
{
    player.setSize(sf::Vector2f(20.f, 100.f));
    player.setFillColor(sf::Color::Red);
}

void Player::drawPlayer(sf::RenderWindow &window)
{
    window.draw(player);
}
