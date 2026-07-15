#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <ctime>

using namespace std;


double f(double x, int k);
void aprox(int n, double * x, double * fx, double * a, double * fx_d);
double ap_val(double xp, double ap, double bp, int n, double * x, double * a);
double diff(double x, int k);
void plot(double ap, double bp, int n, double *x, double *a, int k);