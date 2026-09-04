#include "Mandelbrot.hpp"

int Mandelbrot::escapeIterations(double a, double b) const
{
    double zA = 0;
    double zB = 0;
    int iterations = 0;
    double tempZA;
    double tempZB;

    for (; iterations < maxIterations && (zA * zA + zB * zB) <= 4.0; iterations++)
    {
        tempZA = zA * zA - zB * zB + a;
        tempZB = zA * zB + zB * zA + b;

        zA = tempZA;
        zB = tempZB;
    }

    return iterations;
}