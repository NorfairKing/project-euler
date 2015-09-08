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

/*
 * Fills an array of booleans with indications of which numbers are prime.
 * Works in O(sqrt(n)) time and is correct up to the given n.
 */
void sieve(bool nums[], int n){
  int i, j;
  nums[0] = false;
  nums[1] = false;
  for (i = 2; i < n; ++i) {
    nums[i] = true;
  }  
  for (i = 2; i*i < n; ++i) {
    if (nums[i]) {
      for (j = i+i; j < n; j += i){
        nums[j] = false;
      }
    }
  }       
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
