#include "Header.h"


void aprox(int n, double *x, double *fx, double *a, double *fx_d)
{
    for (int i = 0; i < 2 * n; i += 2)
    {
        a[i] = fx[i / 2];
        a[i + 1] = fx[i / 2];
    }

    for (int i = 2 * n - 1; i >= 1; i--)
    {
        if (x[i / 2] == x[(i - 1) / 2])
        {
            a[i] = fx_d[i / 2];
        }
        else
        {
            a[i] = (a[i] - a[i - 1]) / (x[i / 2] - x[(i - 1) / 2]);
        }
    }

    for (int j = 2; j < 2 * n; j++)
    {
        for (int i = 2 * n - 1; i >= j; i--)
        {
            a[i] = (a[i] - a[i - 1]) / (x[i / 2] - x[(i - j) / 2]);
        }
    }
}



double ap_val(double xp, double ap, double bp, int n, double *x, double *a)
{
    double sum = a[2 * n - 1];
    for (int i = 2 * n - 2; i >= 0; i--) {
        sum = sum * (xp - x[i / 2]) + a[i];
    }
    return sum;
}