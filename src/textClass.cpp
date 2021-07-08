#include "textClass.hpp"

TextClass::TextClass()
{
    if (!font.loadFromFile("./res/arial_narrow_7.ttf")) {
        std::cout << "error loading font\n";
    }
    menu.setString("Would you like to start a new game?\n [Q] - QUIT\n [P] - PLAY");
    menu.setFont(font);
    menu.setCharacterSize(30);

    pause.setString("Game paused\n [Q] - QUIT\n [R] - RESUME");
    pause.setFont(font);
    pause.setCharacterSize(30);

    info.setString("[Esc] - Pause");
    info.setFont(font);
    info.setCharacterSize(15);

    score.setFont(font);
    score.setCharacterSize(25);
}


void TextClass::displayMenu(sf::RenderWindow &window)
{
    menu.setPosition(sf::Vector2f(window.getSize().x/2.f - menu.getGlobalBounds().width/2,
                                  window.getSize().y/2.f));
    window.draw(menu);
}

void TextClass::displayPause(sf::RenderWindow &window)
{
    pause.setPosition(sf::Vector2f(window.getSize().x/2.f - pause.getGlobalBounds().width/2,
                                  window.getSize().y/2.f));
    window.draw(pause);
}

void TextClass::displayInfo(sf::RenderWindow &window)
{
    info.setPosition(sf::Vector2f(0.f, 0.f));
    window.draw(info);
}

void TextClass::displayScore(sf::RenderWindow &window, int &p1Score, int &p2Score)
{
    score.setPosition(sf::Vector2f(window.getSize().x/2.f - score.getGlobalBounds().width/2, 0));
    score.setString("Player 1: " + std::to_string(p1Score) + "\tPlayer 2: " + std::to_string(p2Score)); 
    window.draw(score);
}
