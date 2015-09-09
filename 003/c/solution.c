#include <stdio.h>
#include <stdbool.h>

#include "factor.h"
#include "prime.h"

long solve(long p);

#ifndef TESTING
int main () {
  long p;
  scanf("%ld", &p);
  printf("%ld\n", solve(p));
  return 0;
}
#endif

long solve(long p) {
  long f = 2;
  while (p > 1) {
    if (is_prime_l(f) && is_factor_l(f, p)) {
      p /= f;
      continue;
    }
    f++;
  }
  return f;
}
