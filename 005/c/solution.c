#include <stdio.h>
#include <stdbool.h>

#include "factors.h"
#include "primes.h"
#include "order.h"

int solve(int p);

#ifndef TESTING
int main () {
    printf("%d\n", solve(20));
    return 0;
}
#endif

int solve(int p) {
    int factors[p+1];
    bool is_prime[p+1];
    int i, j, num, found;

    sieve(is_prime, p+1);

    for (i = 2; i <= p ; i++) {
        factors[i] = 0; num = i; j = 2; found = 0;
        while (num > 1) {
            if (is_prime[j] && is_evenly_divisible_by(num, j)) {
                found++; num /= j;
            } else {
                factors[j] = max(found, factors[j]);
                found = 0; j++;
            }
        }
        factors[j] = max(found, factors[j]);
    }

    int result = 1;
    for (i = 2; i <= p; i++) {
        if (is_prime[i]) {
            for (j = 0; j < factors[i]; j++) {
                result *= i;
            }
        }
    }
    return result;
}
