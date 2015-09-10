#include <iostream>

#include "prime_sieve.h"

#define PRIME_SIEVE_DEFAULT_CAPACITY 1

PrimeSieve::PrimeSieve() : PrimeSieve(PRIME_SIEVE_DEFAULT_CAPACITY) {}

PrimeSieve::PrimeSieve(int m) {
  int n = std::max(3, m); // Filling in three elements already.
  prime = std::vector<bool>(n, true);
  prime[0] = false;
  prime[1] = false;
  prime[2] = true;
  upto = 1;

  size_up(n);
}

void PrimeSieve::size_up(int m) {
  if (upto * upto >= m) { return; } // Don't need to size up
  int p = upto * upto; // Previous size
  int newupto = upto;
  while (newupto * newupto < m) { newupto++; } // Need to size up
  int n = newupto * newupto; // Upto upto^2
  prime.resize(n + 1, true); // Get new elements ready

  // First sieve the lower primes again because the newest elements haven't been
  // checked for them yet.
  for (int i = 2; i < upto; ++i) {
    if (prime[i]) {
      for (int j = std::max(i * (p / i) + i, i + i); j <= n; j += i) {
        prime[j] = false;
      }
    } else {
    }
  }

  // Then sieve the primes above what was already checked.
  int i;
  for (i = upto; i * i <= n; ++i) {
    if (prime[i]) {
      for (int j = i + i; j <= n; j += i){
        prime[j] = false;
      }
    } else {
    }
  }
  upto = i - 1; // Counted one too many.
}

bool PrimeSieve::is_prime(int n) {
  size_up(n);
  return prime[n];
}

bool PrimeSieve::operator[] (const int n) {
  return is_prime(n);
}
