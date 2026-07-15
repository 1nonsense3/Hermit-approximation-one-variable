#include "Header.h"

void plot(double ap, double bp, int n, double *x, double *a, int k)
{
    FILE *gp = popen("gnuplot -persist", "w");
    if (!gp) {
        std::cerr << "Cannot start gnuplot\n";
        return;
    }

    const int samples = 1000;

    double y1 = f(ap, k);
    double y2 = ap_val(ap, ap, bp, n, x, a);

    double ymin = (y1 < y2 ? y1 : y2);
    double ymax = (y1 > y2 ? y1 : y2);
    double maxAbs = std::fabs(ymin) > std::fabs(ymax) ? std::fabs(ymin) : std::fabs(ymax);

    for (int i = 0; i < samples; i++) {
        double xp = ap + (bp - ap) * i / (samples - 1);

        double v1 = f(xp, k);
        double v2 = ap_val(xp, ap, bp, n, x, a);

        if (v1 < ymin) ymin = v1;
        if (v1 > ymax) ymax = v1;
        if (v2 < ymin) ymin = v2;
        if (v2 > ymax) ymax = v2;

        if (std::fabs(v1) > maxAbs) maxAbs = std::fabs(v1);
        if (std::fabs(v2) > maxAbs) maxAbs = std::fabs(v2);
    }

    std::cout << "max |y| = " << maxAbs << "\n";

    double dy = ymax - ymin;
    if (dy < 1e-12) dy = 1.0;

    fprintf(gp, "set term qt\n");
    fprintf(gp, "set grid\n");
    fprintf(gp, "set key left top\n");
    fprintf(gp, "set xrange [%lf:%lf]\n", ap, bp);
    fprintf(gp, "set yrange [%lf:%lf]\n", ymin - 0.1 * dy, ymax + 0.1 * dy);
    

    fprintf(gp, "plot '-' with lines lw 2 title 'f(x)', " "'-' with lines lw 2 title 'approx'\n");

    for (int i = 0; i < samples; i++) 
    {
        double xp = ap + (bp - ap) * i / (samples - 1);
        fprintf(gp, "%lf %lf\n", xp, f(xp, k));
    }
    fprintf(gp, "e\n");

    for (int i = 0; i < samples; i++) {
        double xp = ap + (bp - ap) * i / (samples - 1);
        fprintf(gp, "%lf %lf\n", xp, ap_val(xp, ap, bp, n, x, a));
    }
    fprintf(gp, "e\n");

    fflush(gp);
    pclose(gp);
}