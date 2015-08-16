#include <stdio.h>
#include <stdbool.h>

#include "factors.h"
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
  long max = 1;
  long i;
  for (i = 1; i <= p; i++){
    if (is_prime(i) && is_factor_l(i, p)){
      max = i;
    }
  }
  return max;
}
