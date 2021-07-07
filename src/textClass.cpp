#include "textClass.hpp"

TextClass::TextClass()
{
    if (!font.loadFromFile("./res/arial_narrow_7.ttf")) {
        std::cout << "error loading font\n";
    }
    menu.setString("Would you like to start a new game?\n [Q] - QUIT\n [P] - PLAY");
    menu.setFont(font);
    menu.setCharacterSize(30);

    score.setFont(font);
    score.setCharacterSize(25);
}


void TextClass::displayMenu(sf::RenderWindow &window)
{
    menu.setPosition(sf::Vector2f(window.getSize().x / 2 - menu.getGlobalBounds().width /2,
                                  window.getSize().y/2));
    window.draw(menu);
}

void TextClass::displayScore(sf::RenderWindow &window, int &p1Score, int &p2Score)
{
    score.setPosition(sf::Vector2f(window.getSize().x / 2 - score.getGlobalBounds().width /2, 0));
    score.setString("Player 1: " + std::to_string(p1Score) + "\tPlayer 2: " + std::to_string(p2Score)); 
    window.draw(score);
}
