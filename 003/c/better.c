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

// [003/explanation.tex]
long solve(long p) {
  long i;
  for (i = 1; i <= p; ++i) {
    if (is_factor_l(i, p) && is_prime_l(p / i)) {
      return p / i;
    }
  }
  return 1;
}
