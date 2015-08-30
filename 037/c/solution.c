#include <stdio.h>
#include <stdbool.h>

#include "prime.h"
#include "digit.h"

#define PRIMES 1000000
int solve();

#ifndef TESTING
int main() {
  printf("%d\n", solve());
}
#endif

bool is_trunctable_prime(bool prime[], int n) {
  if (!prime[n]) { return false; }
  int nrd = nr_of_digits(n);
  int i;
  for (i = 1; i < nrd; ++i) {
    if (!prime[n/(int)pow(10,i)]) { return false; }
  }
  for (i = 1; i < nrd; ++i) {
    if (!prime[n%(int)pow(10,i)]) { return false; }
  }
  return true;
}

int solve() {
  bool prime[PRIMES];
  sieve(prime, PRIMES);

  int count = 0, sum = 0;
  int i = 10;
  while (count < 11) {
    if (is_trunctable_prime(prime, i)) {
      sum += i;
      ++count;
    }
    ++i;
  }
  return sum;
}
