#include <stdio.h> 
#include <math.h>
#include "factors.h"

int solve(int p);
double geom(double k, double f);

#ifndef TESTING
int main () {
  int p;
  scanf("%d", &p);
  printf("%d\n", solve(p));
  return 0;
}
#endif

int solve (int p) {
  double cte = 1/sqrt(5);
  double phi = (1 + sqrt(5)) / 2.0;
  double psi = 2.0 / (1 + sqrt(5)); // 1/phi
  double phi3 = phi * phi * phi;
  double psi3 = psi * psi * psi;
  double n = floor(log(p * sqrt(5))/log(phi) + 1/2.0);
  double k = floor(n/3.0);
  double term1 = geom(k, phi3);
  double term2 = geom(k, psi3);
  return (int) (cte * (phi3*term1 + psi3*term2));
}

double geom(double k, double f){
  return (1 - pow(f,k))/(1-f);
}
