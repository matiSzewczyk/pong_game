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

void Player::playerMovement(float &dT, const char &nr)
{
    if (nr =='1') {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            this->player.move(-600.f * dT, 0);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            this->player.move(600.f * dT, 0);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            this->player.move(0, -600.f * dT);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            this->player.move(0, 600.f * dT);
        }
    }

    if (nr =='2') {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            this->player.move(-600.f * dT, 0);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            this->player.move(600.f * dT, 0);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            this->player.move(0, -600.f * dT);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            this->player.move(0, 600.f * dT);
        }
    }
}

void Player::drawPlayer(sf::RenderWindow &window)
{
    window.draw(this->player);
}
