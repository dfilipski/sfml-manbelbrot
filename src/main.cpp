#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, const char *argv[])
{
    sf::RenderWindow window(sf::VideoMode({1000, 1000}), "Mandelbrot Set");
    window.setFramerateLimit(60);

    sf::RectangleShape rectangle({100, 100});
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition({500, 500});

    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        // Clear the Screen
        window.clear(sf::Color(80, 80, 80));

        // Draw
        window.draw(rectangle);

        // Update the window
        window.display();
    }
}