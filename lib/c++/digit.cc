#include <vector>

#include "digit.h"
#include "base.h"

/*
 * Gets the number of digits in a given number.
 */
int nr_of_digits(int p) {
  if (p < BASE) { return 1; }
  return nr_of_digits(p / BASE) + 1;
}

/*
 * Calculates the number represented by the first n digits in an array of digits.
 * Whether the numbers in the array actually represent digits is not checked.
 */
int from_digits(int digit[], int n) {
  int j; int num = 0;
  for (j = 0; j < n; j++){
    num += digit[j] * pow(BASE, n - 1 - j);
  }
  return num;
}

/*
 * Gets a vector of the digits of n in reverse order.
 */
std::vector<int> digits(int n) {
  std::vector<int> digits;
  while (n > 0) {
    digits.push_back(n % BASE);
    n /= BASE;
  }
  return digits;
}
