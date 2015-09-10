#include <iostream>

#include "factor.h"
#include "prime_sieve.h"

long solve(long p);

#ifndef TESTING
int main () {
  long p;
  std::cin >> p;
  std::cout << solve(p) << std::endl;
}
#endif

// [003/explanation.tex]
long solve(long p) {
  PrimeSieve is_prime;
  int f = 2;
  while (p > 1) {
    if (is_prime[f] && p % f == 0) {
      p /= f;
      continue;
    }
    f++;
  }
  return f;
}
