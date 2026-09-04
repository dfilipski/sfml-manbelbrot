#ifndef MANDELBROT_RENDERER_H
#define MANDELBROT_RENDERER_H

#include <SFML/Graphics.hpp>

#include "Mandelbrot.hpp"

class MandelbrotRenderer : public sf::Drawable
{
public:
    MandelbrotRenderer(Mandelbrot mandelbrot) : mandelbrot(mandelbrot)
    {
    }

private:
    Mandelbrot mandelbrot;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif // MANDELBROT_RENDERER_H