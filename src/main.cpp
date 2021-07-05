#include <SFML/Graphics.hpp>

int main()
{
    //komentarz cnjxzkjcnzkjnx
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "first project", sf::Style::Fullscreen);

    sf::RectangleShape square(sf::Vector2f(50.f, 50.f));
    square.setFillColor(sf::Color::Red);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        
        window.draw(square);
        
        window.display();
    }
    return EXIT_SUCCESS;
}
