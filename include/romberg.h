// romberg.h
#ifndef ROMBERG_H
#define ROMBERG_H

double romberg(double (*f)(double, void *), double a, double b, void *params);
double trapezoidal(double (*f)(double, void *), double a, double b, int n, void *params);

#endif
