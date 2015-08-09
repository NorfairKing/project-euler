#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "primes.h"

int solve(int p);

#ifndef TESTING
int main () {
    printf("%d\n", solve(10001));
    return 0;
}
#endif

int solve(int p) {
    int n = ceil(p*log(p)+p*log(log(p))); // Large enough.
    bool primes[n];
    sieve(primes, n);

    // https://en.wikipedia.org/wiki/Prime_number_theorem#Approximations_for_the_nth_prime_number
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
