#ifndef MANDELBROT_H
#define MANDELBROT_H

class Mandelbrot
{
public:
    Mandelbrot(int maxIterations) : maxIterations(maxIterations)
    {
    }

    const int maxIterations;

    int escapeIterations(double a, double b) const;
private:
};

#endif // MANDELBROT_H