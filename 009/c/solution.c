#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "primes.h"

int solve(int p);

#ifndef TESTING
int main () {
    printf("%d\n", solve(1000));
    return 0;
}
#endif

int solve(int p) {
    int a; int b; int c;
    for (a = 0; a < p; a++) {
        for (b = a + 1; b < p; b++) {
            for (c = b + 1; c < p; c++) {
                if (a + b + c == p && a*a + b*b == c*c) {
                    return a*b*c;
                }
            }
        }
    }
    return -1;
}
