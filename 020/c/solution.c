#include <stdbool.h>
#include <stdio.h>

#include <base.h>
#include <digit.h>

int solve(int n);

#ifndef TESTING
int main() {
  int n;
  scanf("%d\n", &n);  // # of digits to print
  printf("%d\n", solve(n));
  return 0;
}
#endif

int solve(int n) {
  int len = 0;
  int i;
  for (i = 1; i < n; i++) {
    len += nr_of_digits(i);
  }

  int num[len];  // Stores the digit in ascending order of significance, this
                 // might seem backward.

  // Set all digits to 0
  for (i = 0; i < len; i++) {
    num[i] = 0;
  }
  num[0] = 1;

  int j;
  int carry = 0;
  for (i = 1; i < n; i++) {
    for (j = 0; j < len; j++) {
      num[j] *= i;
      num[j] += carry;
      carry = num[j] / BASE;
      num[j] %= BASE;
    }
  }

  // Sum all the digits together.
  int tot = 0;
  for (i = 0; i < len; i++) {
    tot += num[i];
  }
  return tot;
}
