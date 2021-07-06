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
    sf::Clock deltaClock;
    float deltaTime;


    Player * playerOne = new Player('1');
    Player * playerTwo = new Player('2');
    while (window.isOpen()) {
        sf::Event event;
        deltaTime = deltaClock.restart().asSeconds();
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
                        delete menuText;
                        break;
                    }
            }
        }
        window.clear();
        if (!gameRunning) {
            menuText->displayMenu(window);
        }
        if (gameRunning) {


            /*
             *In order to simplify things, I'm going to use real time movement handling
             *instead of using flags through sf::Event (inside the pollEvent loop above)
             */
            playerOne->playerMovement(deltaTime, '1');
            playerTwo->playerMovement(deltaTime, '2');

            playerOne->drawPlayer(window);
            playerTwo->drawPlayer(window);

        }
        
        window.display();
    }
    return EXIT_SUCCESS;
}
