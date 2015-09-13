#include <iostream>

#include "prime_sieve.h"

static constexpr size_t PRIME_SIEVE_DEFAULT_CAPACITY = 1;

PrimeSieve::PrimeSieve() : PrimeSieve(PRIME_SIEVE_DEFAULT_CAPACITY) {}

PrimeSieve::PrimeSieve(int m) : sieve(std::max(3,m), true) {
  sieve[0] = sieve[1] = false;
  resieve(2, sieve.size(), 0);
}

void PrimeSieve::resieve(size_t from, size_t to, size_t jstart) {
  for (; from != to; ++from) {
    if (sieve[from]) {
      for (size_t j = std::max(jstart/from*from, from*from); j < sieve.size(); j += from) {
        sieve[j] = false;
      }
    }
  }
}

void PrimeSieve::resize(size_t n) {
  if (sieve.size() > n) { return; }

  size_t old = sieve.size();
  sieve.resize(n + 1, true);

  resieve(2, old, old); // from 2 to old, starting at old
  resieve(old, sieve.size(), 0); // from old to n
}

bool PrimeSieve::is_prime(int n) {
  resize(n);
  return sieve[n];
}

bool PrimeSieve::operator[] (const int n) {
  return is_prime(n);
}
