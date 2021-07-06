#include <SFML/Graphics.hpp>

int main()
{
    // should match the desktop resolution
    sf::RenderWindow window(sf::VideoMode().getDesktopMode(),
                            "first project",
                            sf::Style::Resize |
                            sf::Style::Close);

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
