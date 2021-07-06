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
        TextClass(const std::string &string);
        void displayMenu(sf::RenderWindow &window);
};
#endif
