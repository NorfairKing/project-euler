#include <stdbool.h>
#include <vector>

#include "factor.h"

/*
 * Tests whether a given long is prime.
 * Works in O(sqrt(n)) time.
 * Does not work on numbers smaller than 2
 */
bool is_prime (int n) {
  if (n == 1){ return false; }
  for (int i = 2; i*i <= n; ++i) {
    if (is_factor(i, n)) {
      return false;
    }
  }
  return true;
}

std::vector<bool> sieve(int n) {
  std::vector<bool> is_prime(n + 1, true);
  is_prime[0] = false;
  is_prime[1] = false;
  for (int i = 2; i*i < n; ++i) {
    if (is_prime[i]) {
      for (int j = i+i; j < n; j += i){
        is_prime[j] = false;
      }
    }
  }       
  return is_prime;
}
