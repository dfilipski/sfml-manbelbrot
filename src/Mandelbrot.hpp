#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <complex>

class Mandelbrot
{
public:
    Mandelbrot(int maxIterations) : maxIterations(maxIterations)
    {
    }

    const int maxIterations;

    int escapeIterations(std::complex<double> c) const;
private:
};

#endif // MANDELBROT_H