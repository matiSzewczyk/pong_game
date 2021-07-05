#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

void something()
{
    std::cout << "thread 2, second thread,  something()\n";
}

void meme()
{
    std::cout << "thread 1, main thread,    meme()\n";
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "test",
                                                      sf::Style::Close |
                                                      sf::Style::Resize);
    sf::RectangleShape player(sf::Vector2f(50.f, 50.f));
    player.setFillColor(sf::Color::Red);

    sf::Clock clock; // creating a clock outside the loop
    float deltaTime;

    bool moveRight = false;
    while (window.isOpen()) {
        sf::Event event;

        // delta time
        // I should use float for deltaTime as i want to multiply movement speed
        // by the amount of time passed, can't do that with dT as sf::Time.
        deltaTime = clock.restart().asSeconds();

        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

                // Handle movement events
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::D) {
                        moveRight = true;
                    }
                    break;
                case sf::Event::KeyReleased:
                    if (event.key.code == sf::Keyboard::D) {
                        moveRight = false;
                    }
                    break;

                default:
                    break;
            }
        }
        window.clear();
        if (moveRight) {
            player.move(200 * deltaTime, 0);
        }

        sf::Thread thread(&something);
        thread.launch();// launch() start whatever process was supposed to be running.
        meme();         // it's not the creation of a thread that does this.
                        // a thread cannot be paused, i can only use sf::sleep(sf::milliseconds(10));
                        // withing the running process                           an example ^
        window.draw(player);
        
        window.display();
    }

    return EXIT_SUCCESS;
}
/* Multi-threading:
 * sf::Thread in action
 *
 * Member function:
 *
 *class MyClass
 *{
 *public:
 *
 *    void func()
 *    {
 *    }
 *};
 *
 *MyClass object;
 *sf::Thread thread(&MyClass::func, &object);
 */

/*
 *
 *  We could try and render in a 2nd thread with the main one handling events and the logic.
 * 
 *  A typical configuration for a multi-threaded program is to handle the window and its events in one thread (the main one), and rendering in another one.
 *  If you do so, there's an important rule to keep in mind: you can't activate a context (window) if it's active in another thread. 
 *  This means that you have to deactivate your window before launching the rendering thread.
 * void renderingThread(sf::Window* window)
 *{
 *    // activate the window's context
 *    window->setActive(true);
 *
 *    // the rendering loop
 *    while (window->isOpen())
 *    {
 *        // draw...
 *
 *        // end the current frame -- this is a rendering function (it requires the context to be active)
 *        window->display();
 *    }
 *}
 *
 *int main()
 *{
 *    // create the window (remember: it's safer to create it in the main thread due to OS limitations)
 *    sf::Window window(sf::VideoMode(800, 600), "OpenGL");
 *
 *    // deactivate its OpenGL context
 *    window.setActive(false);
 *
 *    // launch the rendering thread
 *    sf::Thread thread(&renderingThread, &window);
 *    thread.launch();
 *
 *    // the event/logic/whatever loop
 *    while (window.isOpen())
 *    {
 *        ...
 *    }
 *
 *    return 0;
 *}
 */
