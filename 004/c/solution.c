#include <stdio.h>
#include <stdbool.h>

#include "palindrome.h"

long solve(long p);

#ifndef TESTING
int main () {
    printf("%ld\n", solve(2));
}
#endif

long solve(long p) {
    int max = 0;
    int lo = pow(10, p - 1); int hi = pow(10, p);
    int i,j,product;
    for (i = lo; i < hi; i++) {
        for (j = lo; j < hi; j++) {
            product = i * j;
            if (product > max && is_palindrome(product)){
                max = product;
            }
        }
    }
    return max;
}
