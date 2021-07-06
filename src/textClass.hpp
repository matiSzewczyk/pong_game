#ifndef TEXTCLASS_HPP
#define TEXTCLASS_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class TextClass
{
    private:
        sf::Text text;
        sf::Font font;

    public:
        TextClass(const std::string &string, sf::RenderWindow &window);
        void displayMenu(sf::RenderWindow &window);
};
#endif
