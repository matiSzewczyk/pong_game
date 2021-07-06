#include "player.hpp"
#include "textClass.hpp"

int main()
{
    // should match the desktop resolution
    sf::RenderWindow window(sf::VideoMode().getDesktopMode(),
                            "Pong Game",
                            sf::Style::Fullscreen);
    
    TextClass * menuText = new TextClass("Would you like to start a new game?\n [q] - QUIT\n [p] - PLAY");
    bool gameRunning = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

                // Handle movement events
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Q && !gameRunning) {
                        delete menuText;
                        window.close();
                        break;
                    }
                    if (event.key.code == sf::Keyboard::P && !gameRunning) {
                        gameRunning = true;
                        std::cout << "clikc";
                        delete menuText;
                        break;
                    }
            }
        }
        window.clear();
        if (!gameRunning) {
            menuText->displayMenu(window);
        }
        
        window.display();
    }
    return EXIT_SUCCESS;
}
