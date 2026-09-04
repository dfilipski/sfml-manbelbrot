#include "Mandelbrot.hpp"

#include <cmath>

int Mandelbrot::escapeIterations(double a, double b) const
{
    // Check if a+bi is in the Main cardiod
    double q = (a - 0.25) * (a - 0.25) + b * b;
    if ((q * (q + a - 0.25) <= b * b / 4.0))
    {
        return maxIterations;
    }

    // Check if a+bi is in the period-2 bulb
    double lhs = (a + 1) * (a + 1) + b * b;
    if (lhs <= 1.0 / 16.0)
    {
        return maxIterations;
    }

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