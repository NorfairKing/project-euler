#include <vector>

#include "digit.h"
#include "base.h"

// Calculates the number of digits of a given number.
int nr_of_digits(int p) {
  if (p < BASE) { return 1; }
  return nr_of_digits(p / BASE) + 1;
}

// Calculates a number from its digital representation.
int from_digits(std::vector<int> digit) {
  int n = digit.size();
  int num = 0;
  for (int j = 0; j < n; j++){
    num += digit[j] * pow(BASE, n - 1 - j);
  }
  return num;
}

// Calculates a vector of the digits of a given number
std::vector<int> digits(int n) {
  std::vector<int> digits(nr_of_digits(n));
  for (int i = n-1; i >= 0; --i) {
    digits[i] = n % BASE;
    n /= BASE;
  }
  return digits;
}
