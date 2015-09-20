#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "base.h"
#include "digit.h"
#include "factor.h"

int solve(int p);

#ifndef TESTING
int main () {
  int p;
  scanf("%d", &p);
  printf("%d\n", solve(p));
  return 0;
}
#endif

int solve(int p) {
  int len = 2 * p;
  int lo = pow(BASE, p - 1);
  int hi = pow(BASE, p);
  int digits[len];
  int i;
  for (i = 0; i < hi; ++i) {
    int j, num;
    for (j = 0, num = i; j < p; ++j, num /= BASE){
      int d = (BASE - 1) - (num % BASE);
      digits[p - j - 1] = d;
      digits[p + j] = d;
    }

    int palindrome = from_digits(digits, len);

    for (j = hi - 1; j >= lo; --j){
      int q = palindrome / j;
      int m = palindrome % j;
      if (m == 0 && q < hi && q > lo) {
        return palindrome;
      }
    }
  }
  return -1;
}
