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
          height(height)
    {
    }

private:
    Mandelbrot mandelbrot;
    const double minRealPart = -2.5;
    const double maxRealPart = 1.0;
    const double minImaginaryPart = -1.2;
    const double maxImaginaryPart = 1.2;
    const unsigned int width;
    const unsigned int height;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    std::complex<double> getNumberForPixel(int x, int y) const;
    sf::Color getColorForIterations(int iterations) const;
};

#endif // MANDELBROT_RENDERER_H