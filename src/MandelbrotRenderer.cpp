#include "MandelbrotRenderer.hpp"

void MandelbrotRenderer::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    sf::RectangleShape rectangle({100, 100});
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition({500, 500});

    target.draw(rectangle);
}
