#include <stdio.h> 
#include <math.h>
#include "factor.h"
#include "constant.h"
#include "series.h"

int solve(int p);

#ifndef TESTING
int main () {
  int p;
  scanf("%d", &p);
  printf("%d\n", solve(p));
  return 0;
}
#endif

// [002/explanation.tex]
int solve (int p) {
  double cte = 1/sqrt(5);
  double h = phi();
  double s = psi();
  double phi3 = h * h * h;
  double psi3 = s * s * s;
  double n = floor(log(p * sqrt(5))/log(h) + 1/2.0);
  double k = floor(n/3.0);
  double term1 = sum_geometric(phi3, k, phi3);
  double term2 = sum_geometric(psi3, k, psi3);
  return (int) (cte * (term1 + term2));
}
