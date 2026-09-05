#include <SFML/Graphics.hpp>
#include <iostream>

#include "MandelbrotRenderer.hpp"

int main(int argc, const char *argv[])
{
    constexpr double zoomSpeed = 1.0;
    constexpr double moveSpeed = 0.5;

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

    sf::Clock clock;
    clock.start();

    bool zoomInHeld = false;
    bool zoomOutHeld = false;
    bool leftHeld = false;
    bool rightHeld = false;
    bool upHeld = false;
    bool downHeld = false;

    window.setKeyRepeatEnabled(false);

    while (window.isOpen())
    {
        const double elapsedSeconds = clock.restart().asSeconds();

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
                    zoomInHeld = true;
                }
                else if (keyPressed->code == sf::Keyboard::Key::Hyphen)
                {
                    zoomOutHeld = true;
                }
                else if (keyPressed->code == sf::Keyboard::Key::Left)
                {
                    leftHeld = true;
                }
                else if (keyPressed->code == sf::Keyboard::Key::Right)
                {
                    rightHeld = true;
                }
                else if (keyPressed->code == sf::Keyboard::Key::Up)
                {
                    upHeld = true;
                }
                else if (keyPressed->code == sf::Keyboard::Key::Down)
                {
                    downHeld = true;
                }
            }
            else if (const auto *released = event->getIf<sf::Event::KeyReleased>())
            {
                if (released->code == sf::Keyboard::Key::Equal)
                {
                    zoomInHeld = false;
                }
                else if (released->code == sf::Keyboard::Key::Hyphen)
                {
                    zoomOutHeld = false;
                }
                else if (released->code == sf::Keyboard::Key::Left)
                {
                    leftHeld = false;
                }
                else if (released->code == sf::Keyboard::Key::Right)
                {
                    rightHeld = false;
                }
                else if (released->code == sf::Keyboard::Key::Up)
                {
                    upHeld = false;
                }
                else if (released->code == sf::Keyboard::Key::Down)
                {
                    downHeld = false;
                }
            }
        }

        if (window.isOpen() && window.hasFocus())
        {
            if (zoomInHeld)
            {
                mandelbrotRenderer.zoom(std::exp(-zoomSpeed * elapsedSeconds));
            }

            if (zoomOutHeld)
            {
                mandelbrotRenderer.zoom(std::exp(zoomSpeed * elapsedSeconds));
            }
            
            if (leftHeld)
            {
                mandelbrotRenderer.pan(-1.0 * moveSpeed * elapsedSeconds, 0);
            }

            if (rightHeld)
            {
                mandelbrotRenderer.pan(1.0 * moveSpeed * elapsedSeconds, 0);
            }

            if (upHeld)
            {
                mandelbrotRenderer.pan(0, 1.0 * moveSpeed * elapsedSeconds);
            }

            if (downHeld)
            {
                mandelbrotRenderer.pan(0, -1.0 * moveSpeed * elapsedSeconds);
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