#include <stdio.h>
#include <stdbool.h>

#include "factors.h"
#include "primes.h"

long solve(long p);

#ifndef TESTING
int main () {
    printf("%ld\n", solve(600851475143));
}
#endif

long solve(long p) {
    long f = 2;
    long product = 1;

    while (product < p){
        f++;
        if (is_prime(f) && is_factor_l(f, p)){
            product *= f;
        }
    }
    return f;
}
