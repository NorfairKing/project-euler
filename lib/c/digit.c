#include <stdbool.h>

#include "base.h"
#include "digit.h"

/*
 * Gets the number of digits in a given number.
 */
int nr_of_digits(int p) {
  if (p < BASE) {
    return 1;
  }
  return nr_of_digits(p / BASE) + 1;
}

/*
 * Gets the nth digit of a given number p.
 * This will be 0 if n is greater than the number of digits of p.
 * Note that digits are counted from _least significant_ to _most significant_
 * and are _zero indexed_. That might seem backwards.
 */
int digit(int n, int p) {
  if (n == 0) {
    return p % BASE;
  }
  return digit(n - 1, p / BASE);
}

/*
 * Calculates the number represented by the first n digits in an array of
 * digits.
 * Whether the numbers in the array actually represent digits is not checked.
 */
int from_digits(int digit[], int n) {
  int j;
  int num = 0;
  for (j = 0; j < n; j++) {
    num += digit[j] * pow(BASE, n - 1 - j);
  }
  return num;
}

/*
 * Fills in the digits of n.
 *
 * digit[]: array of digits, in increasing order of significance. This might
 * seem backward.
 * nrd: length of the array, must be greater than or equal to nr_of_digits(n)
 * n: number to break down
 */
void fill_digits(int digit[], int nrd, int n) {
  int ix = nrd - 1;
  while (n > 0) {
    digit[ix--] = n % BASE;
    n /= BASE;
  }
}
