#include <stdio.h> 
#include <math.h>
#include "factors.h"

int solve(int p);
double geom(double k, double f);
double n(int fn);
double phi(){return ((1 + sqrt(5)) / 2.0);}

#ifndef TESTING
int main () {
    printf("%d\n", solve(4000000));
}
#endif

int solve (int p) {
    double cte = 1/sqrt(5);
    double phi3 = phi()*phi()*phi();
    double iphi3 = -1.0/phi3;
    double k = floor(n(p)/3.0);
    double term1 = geom(k, phi3);
    double term2 = geom(k, iphi3);
    return (int) ceil(cte * (phi3*term1 + iphi3*term2));
}

double geom(double k, double f){
    return (1 - pow(f,k))/(1-f);
}

double n(int fn) {
    return floor(log(fn * sqrt(5))/log(phi()) + 1/2.0);
}
