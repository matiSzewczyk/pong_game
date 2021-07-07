#include "player.hpp"
#include "textClass.hpp"
#include "ball.hpp"

int main()
{
    // should match the desktop resolution
    sf::RenderWindow window(sf::VideoMode().getDesktopMode(),
                            "Pong Game", 
                            sf::Style::Fullscreen);
    
    TextClass * menuText = new TextClass("Would you like to start a new game?\n [Q] - QUIT\n [P] - PLAY", window);
    bool gameRunning = false;
    sf::Clock deltaClock;
    float deltaTime;

    sf::Vector2f playerPos;

    bool p1MoveUp = false, p1MoveDown = false, p1MoveLeft = false, p1MoveRight = false;
    bool p2MoveUp = false, p2MoveDown = false, p2MoveLeft = false, p2MoveRight = false;

    Player * playerOne = new Player('1');
    Player * playerTwo = new Player('2');

    Ball ball;

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
                    // Main menu key presses
                    if (event.key.code == sf::Keyboard::Q && !gameRunning) {
                        delete menuText;
                        delete playerOne;
                        delete playerTwo;
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
            // Update positions.
            playerOne->getPlayerPos();
            playerTwo->getPlayerPos();
            ball.getBallPosition();
            std::cout << "PlayerTwo main: " << playerTwo->getGlobalBounds().left << std::endl;
            // Player One Movement.
            playerOne->playerMoveUp(deltaTime, p1MoveUp, playerPos);
            playerOne->playerMoveDown(deltaTime, p1MoveDown, window);
            playerOne->playerMoveLeft(deltaTime, p1MoveLeft);
            playerOne->playerMoveRight(deltaTime, p1MoveRight, window);
            // Player Two Movement.
            playerTwo->playerMoveUp(deltaTime, p2MoveUp, playerPos);
            playerTwo->playerMoveDown(deltaTime, p2MoveDown, window);
            playerTwo->playerMoveLeft(deltaTime, p2MoveLeft);
            playerTwo->playerMoveRight(deltaTime, p2MoveRight, window);
            // Ball movement.
            ball.ballMovement(deltaTime);
            ball.checkColision(playerOne, playerTwo);
            // Draw stuff.
            playerOne->drawPlayer(window);
            playerTwo->drawPlayer(window);
            ball.drawBall(window);
        }
        window.display();
    }
    return EXIT_SUCCESS;
}
