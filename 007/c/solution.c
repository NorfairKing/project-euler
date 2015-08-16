#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "prime.h"

int solve(int p);

#ifndef TESTING
int main () {
  int p;
  scanf("%d", &p);
  printf("%d\n", solve(p));
  return 0;
}
#endif

int solve(int p) {
    // https://en.wikipedia.org/wiki/Prime_number_theorem#Approximations_for_the_nth_prime_number
    int n = ceil(p*log(p)+p*log(log(p))); // Large enough.
    bool primes[n];
    sieve(primes, n);

    int j = 0; // j is the
    int i = 0; // ith prime
    while (i < p) {
        j++;
        if (primes[j]){
            i++;
        }
    }
    return j;
}
