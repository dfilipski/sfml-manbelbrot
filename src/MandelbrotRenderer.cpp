#include "MandelbrotRenderer.hpp"

#include <iostream>
#include <vector>

void MandelbrotRenderer::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    // Make the sprite
    std::vector<std::uint8_t> pixels(width * height * 4);

    sf::Texture texture;
    if (!texture.resize({width, height}))
    {
        // Failed to resize texture
        throw std::runtime_error("Failed to resize texture for sprite.");
    }

    sf::Sprite mandelbrotSet(texture);

    for (unsigned int y = 0; y < height; y++)
    {
        for (unsigned int x = 0; x < width; x++)
        {
            std::size_t index = (y * width + x) * 4;
            std::complex<double> number = getNumberForPixel(x, y);
            int iterations = mandelbrot.escapeIterations(number);
            sf::Color color = getColorForIterations(iterations);

            pixels[index] = color.r;
            pixels[index + 1] = color.g;
            pixels[index + 2] = color.b;
            pixels[index + 3] = color.a;
        }
    }

    texture.update(pixels.data());

    target.draw(mandelbrotSet);
}

std::complex<double> MandelbrotRenderer::getNumberForPixel(int x, int y) const
{
    double a = minRealPart + static_cast<double>(x) / static_cast<double>(width) * (maxRealPart - minRealPart);
    double b = maxImaginaryPart - static_cast<double>(y) / static_cast<double>(height) * (maxImaginaryPart - minImaginaryPart);
    std::complex<double> c(a,b);

    return c;
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