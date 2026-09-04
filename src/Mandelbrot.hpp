#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <complex>

class Mandelbrot
{
public:
    int escapeIterations(std::complex<double> c, int maxIterations);

private:
};

#endif // MANDELBROT_H