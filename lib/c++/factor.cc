#include "factor.h"

/*
 * Test whether a given number is even, that is, divisible by 2.
 */
bool even(int n) {
    return ! odd(n);
}

/*
 * Test whether a given number is odd, that is, not divisible by 2.
 */
bool odd(int n) {
    return n & 1;
}

/*
 * Test whether a given number divides a given other number
 */
bool divides(int n, int m) {
    if (n == 0) {
        return false;
    }
    if (m == 0) {
        return true;
    }
    return ((m % n) == 0);
}

bool divides_l(long n, long m) {
    if (n == 0) {
        return false;
    }
    if (m == 0) {
        return true;
    }
    return ((m % n) == 0);
}

/*
 * Tests whether a given number is a factor of another given number.
 * n is a factor of m if n divides m.
 */
bool is_factor(int n, int m) { return divides(n, m); }

/*
 * Tests whether a given number is evenly divisible by another given number.
 * n is evenly divisible by m if m divides n.
 */
bool is_evenly_divisible_by(int n, int m) { return divides(m, n); }

/*
 * Returns the number of proper dividers (less than and while divisor)
 * of a given number.
 */
int nr_divisors(int n) {
    if (n == 0) {
        return 0;
    }
    int d = 1;  // n is always divisible by 1.
    int i;
    for (i = 2; i * i < n; ++i) {  // Don't check sqrt(n)
        if (is_evenly_divisible_by(n, i)) {
            d += 2;
        }
    }
    // Check sqrt(n) seperately because otherwise the divisor is counted doubly.
    if (i * i == n && is_evenly_divisible_by(n, i)) {
        d++;
    }
    return d;
}

/*
 * Fills a given array of integers with the number of proper divisors for
 * each number.
 */
void fill_nr_divisors(int divs[], int n) {
    int i, j;
    divs[0] = 0;
    for (i = 1; i < n; ++i) {
        divs[i] = 1;
    }
    for (i = 2; i <= n/2; ++i) {
        for (j = i+i; j < n; j += i) {
            ++divs[j];
        }
    }
}

int sum_divisors(int n){
    if (n == 0) {
        return 0;
    }
    int sum = 1;  // n is always divisible by 1.
    int i;
    for (i = 2; i * i < n; ++i) {  // Don't check sqrt(n)
        if (is_evenly_divisible_by(n, i)) {
            sum += i + n/i;
        }
    }
    // Check sqrt(n) seperately because otherwise the divisor is counted doubly.
    if (i * i == n && is_evenly_divisible_by(n, i)) {
        sum += i;
    }
    return sum;
}

void fill_sum_divisors(int divs[], int n){
    int i, j;
    divs[0] = 0;
    for (i = 1; i < n; ++i) {
        divs[i] = 1;
    }
    for (i = 2; i <= n/2; ++i) {
        for (j = i+i; j < n; j += i) {
            divs[j] += i;
        }
    }
}
