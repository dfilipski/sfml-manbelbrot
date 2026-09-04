#include "Mandelbrot.hpp"

int Mandelbrot::escapeIterations(std::complex<double> c) const
{
    std::complex<double> z(0.0, 0.0);
    int iterations = 0;

    for (; iterations < maxIterations && std::norm(z) <= 4.0; iterations++)
    {
        z = z * z + c;
    }

    return iterations;
}