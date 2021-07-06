#include "textClass.hpp"

TextClass::TextClass(const std::string &string)
{
    if (!font.loadFromFile("./res/arial_narrow_7.ttf")) {
        std::cout << "error loading font\n";
    }
    text.setString(string);
    text.setFont(font);
    text.setCharacterSize(30);
}


void TextClass::displayMenu(sf::RenderWindow &window)
{
    window.draw(this->text);
}
