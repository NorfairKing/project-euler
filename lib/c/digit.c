#include <stdbool.h>

#include "digit.h"

/*
 * Gets the number of digits in a given number.
 */
int nr_of_digits(int p) {
    if (p < 10) { return 1; }
    return nr_of_digits(p / 10) + 1;
}

/*
 * Gets the nth digit of a given number p.
 * This will be 0 if n is greater than the number of digits of p.
 * Note that digits are counted from _least significant_ to _most significant_
 * and are _zero indexed_. That might seem backwards.
 */
int digit(int n, int p) {
    if (n == 0) { return p % 10; }
    return digit(n-1, p/10);
}
