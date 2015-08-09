#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "primes.h"

long solve(int p);

#ifndef TESTING
int main () {
    printf("%ld\n", solve(2000000));
    return 0;
}
#endif

long solve(int p) {
    bool prime[p];
    sieve(prime, p);

    long sum = 0;
    int i;
    for (i = 0; i < p; i++) {
        if (prime[i]) {
            sum += i;
        }
    }
    return sum;
}
