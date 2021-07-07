#ifndef TEXTCLASS_HPP
#define TEXTCLASS_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class TextClass
{
    private:
        sf::Text menu;
        sf::Text score;
        sf::Font font;

    public:
        TextClass();
        void displayMenu(sf::RenderWindow &window);
        void displayScore(sf::RenderWindow &window, int &p1Score, int &p2Score);
};
#endif
