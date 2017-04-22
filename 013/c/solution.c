#include <stdbool.h>
#include <stdio.h>

#include "base.h"
#include "digit.h"

long long solve(int n, int p, int r, int ds[r][p]);

#ifndef TESTING
int main() {
  int n, p, r;
  scanf("%d\n", &n);  // # of digits to print
  scanf("%d\n", &p);  // # of digits per number
  scanf("%d\n", &r);  // # of numbers
  int ds[r][p];
  int i, j;
  for (i = 0; i < r; i++) {
    for (j = 0; j < p; j++) {
      scanf("%1d", &(ds[i][j]));
    }
    scanf("\n");
  }
  printf("%lld\n", solve(n, p, r, ds));
  return 0;
}
#endif

long long solve(int n, int p, int r, int ds[r][p]) {
  int tnds = p + nr_of_digits(r) + 1;  // Upper bound for the total number of
                                       // digits in the sum of the numbers
  int digitsum[tnds];
  int i, j;
  for (i = 0; i < tnds; i++) {
    digitsum[i] = 0;  // Set digits of the sum to 0 to start, because we don't
                      // know whether the last digits will be used.
  }
  // First add all numbers together, digit-wise
  // The digits are stored in reverse order, so we can start at index 0 in the
  // next step.
  for (i = 0; i < r; i++) {
    for (j = 0; j < p; j++) {
      digitsum[j] += ds[i][p - j - 1];
    }
  }

  // Now carry over the digits.
  for (i = 0; i < tnds - 1; i++) {
    int num = digitsum[i];
    int digit = num % BASE;
    int carry = num / BASE;
    digitsum[i] = digit;
    digitsum[i + 1] = digitsum[i + 1] + carry;
  }

  int fdi = tnds - 1;  // Index of the first nonzero digit
  while (digitsum[fdi] == 0) {
    fdi--;
  }

  // (We will need more than 32 bits to house 10 digits.)
  long long result = 0;
  for (i = 0; i < n; i++) {
    result *= (long long)BASE;
    result += (long long)(digitsum[fdi - i]);
  }

  return result;
}
