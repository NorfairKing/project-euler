#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "prime.h"

long solve(int p);

#ifndef TESTING
int main () {
  int p;
  scanf("%d", &p);
  printf("%ld\n", solve(p));
  return 0;
}
#endif

long solve(int p) {
  bool prime[p];
  sieve(prime, p);

  long sum = 0;
  int i;
  for (i = 0; i < p; i++) {
    if (prime[i]) {
      sum += i;
    }
  }
  return sum;
}
