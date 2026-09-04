#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, const char *argv[])
{
    std::cout << argc << std ::endl;
    int resolutionX = 1000;
    int resolutionY = 1000;

    if (argc == 3)
    {
        resolutionX = std::stoi(argv[1]);
        resolutionY = std::stoi(argv[2]);
    }

    sf::RenderWindow window(sf::VideoMode({static_cast<unsigned int>(resolutionX), static_cast<unsigned int>(resolutionY)}), "Mandelbrot Set");
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