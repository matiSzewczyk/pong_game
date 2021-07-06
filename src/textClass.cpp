#include "textClass.hpp"

TextClass::TextClass(const std::string &string, sf::RenderWindow &window)
{
    if (!font.loadFromFile("./res/arial_narrow_7.ttf")) {
        std::cout << "error loading font\n";
    }
    text.setString(string);
    text.setFont(font);
    text.setCharacterSize(30);
    text.setPosition(sf::Vector2f(window.getSize().x / 2 - text.getLocalBounds().width /2,
                                  window.getSize().y/2));
}


void TextClass::displayMenu(sf::RenderWindow &window)
{
    window.draw(this->text);
}
