#include "player.hpp"
#include "textClass.hpp"
#include "ball.hpp"

int main()
{
    // should match the desktop resolution
    sf::RenderWindow window(sf::VideoMode().getDesktopMode(),
                            "Pong Game", 
                            sf::Style::Fullscreen);
    
    int p1Score = 0, p2Score = 0;
    TextClass * menuText = new TextClass();
    TextClass * scoreText = new TextClass();
    bool gameRunning = false;
    sf::Clock deltaClock;
    float deltaTime;

    sf::Vector2f playerPos;

    bool p1MoveUp = false, p1MoveDown = false;
    bool p2MoveUp = false, p2MoveDown = false;

    Player * playerOne = new Player('1', window);
    Player * playerTwo = new Player('2', window);

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
                        default:
                            break;
                    }
                    // Main menu key presses
                    if (event.key.code == sf::Keyboard::Q && !gameRunning) {
                        delete menuText;
                        delete scoreText;
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
                        default:
                            break;
                    }
                    break;
                default:
                    break;
                    
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
            // Player One Movement.
            playerOne->playerMoveUp(deltaTime, p1MoveUp, playerPos);
            playerOne->playerMoveDown(deltaTime, p1MoveDown, window);
            // Player Two Movement.
            playerTwo->playerMoveUp(deltaTime, p2MoveUp, playerPos);
            playerTwo->playerMoveDown(deltaTime, p2MoveDown, window);
            // Ball movement.
            ball.ballMovement(deltaTime);
            ball.checkColision(playerOne, playerTwo, window, p1Score, p2Score);
            // Draw stuff.
            playerOne->drawPlayer(window);
            playerTwo->drawPlayer(window);
            ball.drawBall(window);
            scoreText->displayScore(window, p1Score, p2Score);
        }
        window.display();
    }
    return EXIT_SUCCESS;
}
