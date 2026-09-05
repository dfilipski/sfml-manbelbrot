#ifndef MANDELBROT_RENDERER_H
#define MANDELBROT_RENDERER_H

#include <SFML/Graphics.hpp>

class MandelbrotRenderer : public sf::Drawable
{
public:
    MandelbrotRenderer(int width, int height) : 
          width(width),
          height(height)
    {
        loadShader("shaders/mandelbrot.frag");
        rectangle = sf::RectangleShape({static_cast<float>(width), static_cast<float>(height)});
    }

    void zoom(double factor);
    void resetZoom();
    void pan(double horizontal, double vertical);

private:
    const double defeaultMinRealPart = -2.5;
    const double defeaultMaxRealPart = 1.0;
    const double defeaultMinImaginaryPart = -1.2;
    const double defeaultMaxImaginaryPart = 1.2;
    double minRealPart = -2.5;
    double maxRealPart = 1.0;
    double minImaginaryPart = -1.2;
    double maxImaginaryPart = 1.2;
    const unsigned int width;
    const unsigned int height;

    sf::Shader shader;
    sf::RectangleShape rectangle;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void loadShader(const char *filePath);
    void updateShaderBounds();
};

#endif // MANDELBROT_RENDERER_H