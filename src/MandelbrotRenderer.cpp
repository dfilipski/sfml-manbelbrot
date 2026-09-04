#include "MandelbrotRenderer.hpp"

#include <iostream>
#include <vector>

void MandelbrotRenderer::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mandelbrotSet);
}

sf::Color MandelbrotRenderer::getColorForIterations(int iterations) const
{
    if (iterations == mandelbrot.maxIterations)
    {
        return sf::Color::Black;
    }
    if (iterations <= 3)
    {
        return sf::Color::Blue;
    }
    if (iterations <= 15)
    {
        return sf::Color(255, 165, 0, 255);
    }
    if (iterations <= 40)
    {
        return sf::Color::Yellow;
    }
    if (iterations <= 100)
    {
        return sf::Color::Red;
    }

    return sf::Color::White;
}

void MandelbrotRenderer::renderMandlebrotSet()
{
    // Make the sprite
    std::vector<std::uint8_t> pixels(width * height * 4);

    for (unsigned int y = 0; y < height; y++)
    {
        double b = maxImaginaryPart - y * imaginaryPartStep;
        double a = minRealPart;

        for (unsigned int x = 0; x < width; x++)
        {
            
            int iterations = mandelbrot.escapeIterations(a,b);

            std::size_t index = (y * width + x) * 4;
            sf::Color color = getColorForIterations(iterations);
            pixels[index] = color.r;
            pixels[index + 1] = color.g;
            pixels[index + 2] = color.b;
            pixels[index + 3] = color.a;

            // Take a step
            a += realPartStep;
        }
    }

    texture.update(pixels.data());
}
