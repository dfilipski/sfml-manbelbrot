#include <SFML/Graphics.hpp>
#include <iostream>

#include "MandelbrotRenderer.hpp"

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

    MandelbrotRenderer mandelbrotRenderer(resolutionX, resolutionY);

    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->code == sf::Keyboard::Key::Space)
                {
                    mandelbrotRenderer.resetZoom();
                }
                else if (keyPressed->code == sf::Keyboard::Key::Equal)
                {
                    mandelbrotRenderer.zoom(0.99);
                }
                else if (keyPressed->code == sf::Keyboard::Key::Hyphen)
                {
                    mandelbrotRenderer.zoom(1.01);
                }
                else if (keyPressed->code == sf::Keyboard::Key::Left)
                {
                    mandelbrotRenderer.pan(-0.01, 0);
                }
                else if (keyPressed->code == sf::Keyboard::Key::Right)
                {
                    mandelbrotRenderer.pan(0.01, 0);
                }
                else if (keyPressed->code == sf::Keyboard::Key::Up)
                {
                    mandelbrotRenderer.pan(0, 0.01);
                }
                else if (keyPressed->code == sf::Keyboard::Key::Down)
                {
                    mandelbrotRenderer.pan(0, -0.01);
                }
            }
        }

        // Clear the Screen
        window.clear(sf::Color::Black);

        // Draw
        window.draw(mandelbrotRenderer);

        // Update the window
        window.display();
    }
}