#include "Header.h"

int main(int argc, char * argv[])
{
    // входные параметры

    double ap = stod(argv[1]);
    double bp = stod(argv[2]);
    int n = stoi(argv[3]);
    int k = stoi(argv[4]);

    double * x = new double[n]; // равномерно распределяем точки по отрезку
    for (int i = 0; i < n; i++)
    {
        x[i] = ap + i * (bp - ap)/ (n - 1);
    }


    double * fx = new double[n]; // считаем значение функции в узлах
    for (int i = 0; i < n; i++)
    {
        fx[i] = f(x[i], k);
    }


    double * fx_d = new double[n]; // считаем значение производной функции в узлах
    for (int i = 0; i < n; i++)
    {
        fx_d[i] = diff(x[i], k);
    }


    double * a = new double[2 * n];

    aprox(n, x, fx, a, fx_d);


    double xp = 0.528;
    cout << f(xp, k) << " " << ap_val(xp, ap, bp, n, x, a) << endl;
    cout << f(xp, k) - ap_val(xp, ap, bp, n, x, a) << endl;

    /*
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << " " << fx[i] << endl;
    }
    */

    // cout << diff(1, k);

    plot(ap, bp, n, x, a, k);

}