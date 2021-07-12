#include "textClass.hpp"

TextClass::TextClass(const std::string &textType)
{
    if (!font.loadFromFile("./res/arial_narrow_7.ttf")) {
        std::cout << "error loading font\n";
    }
    // To ensure all these sf::Text objects aren't created for no reason
    // if the TextClass object will  only use one of these, we pass a flag
    // to determine which sf::Text should be created
    if (textType == "menu") {
        menu.setString("Would you like to start a new game?\n [Q] - QUIT\n [P] - PLAY");
        menu.setFont(font);
        menu.setCharacterSize(30);
    }
    else if (textType == "pause") {
        pause.setString("Game paused\n [Q] - QUIT\n [C] - Continue\n [R] - RESTART");
        pause.setFont(font);
        pause.setCharacterSize(30);
    }
    else if (textType == "info") {
        info.setString("\t[Esc] - Pause");
        info.setFont(font);
        info.setCharacterSize(15);
        info.setFillColor(sf::Color::Black);
        info.setOutlineColor(sf::Color::Black);
    }
    else if (textType == "score") {
        score.setFont(font);
        score.setCharacterSize(35);
    }
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
    score.setPosition(sf::Vector2f(window.getSize().x/2.f - score.getGlobalBounds().width/2, 25.f));
    score.setString(std::to_string(p1Score) + "\t\t\t" + std::to_string(p2Score)); 
    window.draw(score);
}
