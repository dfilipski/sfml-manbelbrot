#include "MandelbrotRenderer.hpp"

#include <iostream>
#include <vector>

void MandelbrotRenderer::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.shader = &shader;
    target.draw(rectangle, states);
}

void MandelbrotRenderer::zoom(double factor)
{
    minRealPart *= factor;
    maxRealPart *= factor;
    minImaginaryPart *= factor;
    maxImaginaryPart *= factor;
    updateShaderBounds();
}

void MandelbrotRenderer::resetZoom()
{
    minRealPart = defeaultMinRealPart;
    maxRealPart = defeaultMaxRealPart;
    minImaginaryPart = defeaultMinImaginaryPart;
    maxImaginaryPart = defeaultMaxImaginaryPart;
    updateShaderBounds();
}

void MandelbrotRenderer::pan(double horizontal, double vertical)
{
    minRealPart += horizontal;
    maxRealPart += horizontal;
    minImaginaryPart += vertical;
    maxImaginaryPart += vertical;
    updateShaderBounds();
}

void MandelbrotRenderer::loadShader(const char *filePath)
{
    if (!shader.loadFromFile(filePath, sf::Shader::Type::Fragment))
    {
        throw std::runtime_error("Failed to load shader");
    }

    shader.setUniform(
        "resolution",
        sf::Glsl::Vec2(
            static_cast<float>(width),
            static_cast<float>(height)));

    updateShaderBounds();
}

void MandelbrotRenderer::updateShaderBounds()
{
    shader.setUniform("minBounds", sf::Glsl::Vec2(
        static_cast<float>(minRealPart),
        static_cast<float>(minImaginaryPart)
    ));

    shader.setUniform("maxBounds", sf::Glsl::Vec2(
        static_cast<float>(maxRealPart),
        static_cast<float>(maxImaginaryPart)
    ));
}