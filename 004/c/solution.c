#include <stdio.h>
#include <stdbool.h>

#include "factors.h"

int solve(int p);

#ifndef TESTING
int main () {
    printf("%d\n", solve(3));
    return 0;
}
#endif

int solve(int p) {
    int i,j,k;
    int divisor;
    int palindrome;
    for (i = 9; i >= 0; i--) {
        for (j = 9; j >= 0; j--) {
            for (k = 9; k >= 0; k--) {
                palindrome = 100000 * i
                           +  10000 * j
                           +   1000 * k
                           +    100 * k
                           +     10 * j
                           +      1 * i;
                for (divisor = 999; divisor >= 100; divisor--) {
                    if (is_evenly_divisible_by(palindrome, divisor) && palindrome / divisor < 1000) {
                        return palindrome;
                    }
                }
            }
        }
    }
    return -1;
}
