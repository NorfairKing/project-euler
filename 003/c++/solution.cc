#include <iostream>

#include "factor.h"
#include "prime.h"

long solve(long p);

#ifndef TESTING
int main () {
  long p;
  std::cin >> p;
  std::cout << solve(p) << std::endl;
}
#endif

long solve(long p) {
  int f = 2;
  while (p > 1) {
    if (is_prime(f) && p % f == 0) {
      p /= f;
      continue;
    }
    f++;
  }
  return f;
}
