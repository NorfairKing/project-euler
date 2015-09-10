#include <iostream>

#include "factor.h"
#include "prime_sieve.h"

int solve(int p);

#ifndef TESTING
int main () {
  int p;
  std::cin >> p;
  std::cout << solve(p) << std::endl;
}
#endif

int solve(int p) {
  PrimeSieve is_prime;

  int factors[p+1];
  int num, found;
  int j;
  for (int i = 2; i <= p ; i++) {
    factors[i] = 0;
    num = i;
    j = 2;
    found = 0;
    while (num > 1) {
      if (is_prime[j] && is_evenly_divisible_by(num, j)) {
        found++; num /= j;
      } else {
        factors[j] = std::max(found, factors[j]);
        found = 0; j++;
      }
    }
    factors[j] = std::max(found, factors[j]);
  }

  int result = 1;
  for (int i = 2; i <= p; i++) {
    if (is_prime[i]) {
      for (int j = 0; j < factors[i]; j++) {
        result *= i;
      }
    }
  }
  return result;
}
