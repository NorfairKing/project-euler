#include <stdio.h>
#include <stdbool.h>

#include "factors.h"
#include "primes.h"

long solve(long p);

#ifndef TESTING
int main () {
    printf("%ld\n", solve(600851475143));
    return 0;
}
#endif

long solve(long p) {
    long max = 1;
    long i;
    for (i = 1; i <= p; i++){
        if (is_prime(i) && is_factor_l(i, p)){
            max = i;
        }
    }
    return max;
}
