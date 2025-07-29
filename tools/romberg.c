// romberg.c
#include <math.h>
#include <stdio.h>
#include "../include/romberg.h"

#define MAX_ITER 20
#define TOL 1e-8

double romberg(double (*f)(double, void *), double a, double b, void *params) {
    double R[MAX_ITER][MAX_ITER];
    int i, j;
    int n = 1;

    R[0][0] = trapezoidal(f, a, b, n, params);

    for (i = 1; i < MAX_ITER; i++) {
        n *= 2;
        R[i][0] = trapezoidal(f, a, b, n, params);
        for (j = 1; j <= i; j++) {
            R[i][j] = (pow(4, j) * R[i][j - 1] - R[i - 1][j - 1]) / (pow(4, j) - 1);
        }
        if (fabs(R[i][i] - R[i - 1][i - 1]) < TOL) {
            return R[i][i];
        }
    }

    fprintf(stderr, "Romberg did not converge\n");
    return R[MAX_ITER - 1][MAX_ITER - 1];
}

double trapezoidal(double (*f)(double, void *), double a, double b, int n, void *params) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a, params) + f(b, params));

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x, params);
    }

    return sum * h;
}
