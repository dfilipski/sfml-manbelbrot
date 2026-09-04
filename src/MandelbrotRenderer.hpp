#ifndef MANDELBROT_RENDERER_H
#define MANDELBROT_RENDERER_H

#include <SFML/Graphics.hpp>
#include <complex>

#include "Mandelbrot.hpp"

class MandelbrotRenderer : public sf::Drawable
{
public:
    MandelbrotRenderer(Mandelbrot mandelbrot, int width, int height)
        : mandelbrot(mandelbrot),
          width(width),
          height(height),
          texture(sf::Vector2u{this->width, this->height}),
          mandelbrotSet(texture)
    {
        renderMandlebrotSet();
    }

private:
    Mandelbrot mandelbrot;
    const double minRealPart = -2.5;
    const double maxRealPart = 1.0;
    const double minImaginaryPart = -1.2;
    const double maxImaginaryPart = 1.2;
    const unsigned int width;
    const unsigned int height;

    sf::Texture texture;
    sf::Sprite mandelbrotSet;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    std::complex<double> getNumberForPixel(int x, int y) const;
    sf::Color getColorForIterations(int iterations) const;

    void renderMandlebrotSet();
};

#endif // MANDELBROT_RENDERER_H