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

    sf::Vector2f playerPos;

    bool p1MoveUp = false, p1MoveDown = false, p1MoveLeft = false, p1MoveRight = false;
    bool p2MoveUp = false, p2MoveDown = false, p2MoveLeft = false, p2MoveRight = false;

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
                    switch (event.key.code) {
                        case sf::Keyboard::W:
                            p1MoveUp = true;
                            break;
                        case sf::Keyboard::Up:
                            p2MoveUp = true;
                            break;
                        case sf::Keyboard::S:
                            p1MoveDown = true;
                            break;
                        case sf::Keyboard::Down:
                            p2MoveDown = true;
                            break;
                        case sf::Keyboard::A:
                            p1MoveLeft = true;
                            break;
                        case sf::Keyboard::Left:
                            p2MoveLeft = true;
                            break;
                        case sf::Keyboard::D:
                            p1MoveRight = true;
                            break;
                        case sf::Keyboard::Right:
                            p2MoveRight = true;
                            break;
                    }

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
                    break;
                case sf::Event::KeyReleased:
                    switch (event.key.code) {
                        case sf::Keyboard::W:
                            p1MoveUp = false;
                            break;
                        case sf::Keyboard::Up:
                            p2MoveUp = false;
                            break;
                        case sf::Keyboard::S:
                            p1MoveDown = false;
                            break;
                        case sf::Keyboard::Down:
                            p2MoveDown = false;
                            break;
                        case sf::Keyboard::A:
                            p1MoveLeft = false;
                            break;
                        case sf::Keyboard::Left:
                            p2MoveLeft = false;
                            break;
                        case sf::Keyboard::D:
                            p1MoveRight = false;
                            break;
                        case sf::Keyboard::Right:
                            p2MoveRight = false;
                            break;
                    }

            }
        }
        window.clear();
        if (!gameRunning) {
            menuText->displayMenu(window);
        }
        if (gameRunning) {
            playerOne->getPlayerPos();
            playerTwo->getPlayerPos();
            // Player Movement
            playerOne->playerMoveUp(deltaTime, p1MoveUp);
            playerOne->playerMoveDown(deltaTime, p1MoveDown);
            playerOne->playerMoveLeft(deltaTime, p1MoveLeft);
            playerOne->playerMoveRight(deltaTime, p1MoveRight);

            playerTwo->playerMoveUp(deltaTime, p2MoveUp);
            playerTwo->playerMoveDown(deltaTime, p2MoveDown);
            playerTwo->playerMoveLeft(deltaTime, p2MoveLeft);
            playerTwo->playerMoveRight(deltaTime, p2MoveRight);

            playerOne->drawPlayer(window);
            playerTwo->drawPlayer(window);

        }
        
        window.display();
    }
    return EXIT_SUCCESS;
}
