#include "MandelbrotRenderer.hpp"

#include <iostream>
#include <vector>

void MandelbrotRenderer::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mandelbrotSet);
}

sf::Color MandelbrotRenderer::getColorForIterations(int iterations) const
{
    sf::Color color = sf::Color::Black;
    if (iterations == mandelbrot.maxIterations)
    {
        return color;
    }

    return color + sf::Color(iterations, iterations, iterations);
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

            int iterations = mandelbrot.escapeIterations(a, b);

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

void MandelbrotRenderer::zoom(double factor)
{
    minRealPart *= factor;
    maxRealPart *= factor;
    minImaginaryPart *= factor;
    maxImaginaryPart *= factor;

    realPartStep = (maxRealPart - minRealPart) / static_cast<double>(width);
    imaginaryPartStep = (maxImaginaryPart - minImaginaryPart) / static_cast<double>(height);
    renderMandlebrotSet();
}

void MandelbrotRenderer::resetZoom()
{
    minRealPart = defeaultMinRealPart;
    maxRealPart = defeaultMaxRealPart;
    minImaginaryPart = defeaultMinImaginaryPart;
    maxImaginaryPart = defeaultMaxImaginaryPart;
    
    realPartStep = (maxRealPart - minRealPart) / static_cast<double>(width);
    imaginaryPartStep = (maxImaginaryPart - minImaginaryPart) / static_cast<double>(height);
    renderMandlebrotSet();
}
