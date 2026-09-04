#include <SFML/Graphics.hpp>
#include <iostream>

#include "Mandelbrot.hpp"
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

    sf::View view = window.getDefaultView();
    sf::View defaultView = view;

    Mandelbrot mandelbrot(500);
    MandelbrotRenderer mandelbrotRenderer(mandelbrot, resolutionX, resolutionY);

    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (const auto *scroll = event->getIf<sf::Event::MouseWheelScrolled>())
            {
                if (scroll->wheel == sf::Mouse::Wheel::Vertical)
                {

                    // Get the mouse position
                    sf::Vector2i mousePixelPos = {scroll->position.x, scroll->position.y};
                    sf::Vector2f mouseWorldPosBefore = window.mapPixelToCoords(mousePixelPos, view);

                    // Apply Zoom factor
                    float zoomFactor = (scroll->delta > 0) ? 0.9f : 1.1f;
                    view.zoom(zoomFactor);

                    // Temporarily update the window to calculate new mouse position
                    window.setView(view);
                    sf::Vector2f mouseWorldPosAfter = window.mapPixelToCoords(mousePixelPos, view);

                    // Shift the view to offset the movement
                    sf::Vector2f offset = mouseWorldPosBefore - mouseWorldPosAfter;
                    view.move(offset);

                    // Apply the final view
                    window.setView(view);
                }
            }
            else if (const auto *keyPress = event->getIf<sf::Event::KeyPressed>())
            {
                view = defaultView;
                window.setView(view);
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