#include "Header.h"

double f(double x, int k)
{
    if (k == 0) 
    {
        return 1;
    }
    else if (k == 1)
    {
        return x;
    }
    else if (k == 2)
    {
        return x*x;
    }
    else if (k == 3)
    {
        return x*x*x;
    }
    else if (k == 4)
    {
        return x*x*x*x;
    }
    else if (k == 5)
    {
        return exp(x);
    }
    else if (k == 6)
    {
        return 1/(25*x*x + 1);
    }
    return 0;
}

double diff(double x, int k)
{
    const double h=1e-10;
    return (f(x + h, k) - f(x - h, k))/(2 * h);
}