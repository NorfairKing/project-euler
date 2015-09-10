#include <iostream>

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

  int j = 0; // j is the
  int i = 0; // ith prime
  while (i < p) {
    j++;
    if (is_prime[j]){
      i++;
    }
  }
  return j;
}
