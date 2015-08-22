#include <stdio.h>
#include "prime.h"

int solve(int p);

#ifndef TESTING
int main () {
  int p;
  scanf("%d", &p);
  printf("%d\n", solve(p));
  return 0;
}
#endif

int solve(int p) {
  int nump = 1000000; // large enough
  bool is_prime[nump];
  sieve(is_prime, nump);

  int a, b, n, prod = 1, max = 0;
  for (a = -p; a < p; a++) {
    for (b = -p; b < p; b++) {
      n = 0;
      while (is_prime[n*n + a*n + b]) {
        n++;
      }
      if (n > max) {
        max = n;
        prod = a*b;
      }
    }
  }
  return prod;
}
