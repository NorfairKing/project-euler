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
 * Calculates the number represented by the first n digits in an array of digits.
 * Whether the numbers in the array actually represent digits is not checked.
 */
int from_digits(int digit[], int n) {
  int j; int num = 0;
  for (j = 0; j < n; j++){
    num += digit[j] * pow(10, n - 1 - j);
  }
  return num;
}
