#include <stdbool.h>
#include <stdio.h>

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
  int len = n;   // Overkill, could have fewer spaces, but this works.
  int num[len];  // Stores the digit in ascending order of significance, this
                 // might seem backward.

  // Start with 2^0
  num[0] = 1;
  int i;
  for (i = 1; i < len; i++) {
    num[i] = 0;
  }

  // raise 'num' to the 'n'th power.
  int j;
  int carry = 0;
  for (i = 1; i <= n; i++) {
    for (j = 0; j < len; j++) {
      num[j] *= 2;
      num[j] += carry;
      carry = num[j] / 10;
      num[j] %= 10;
    }
  }

  // Sum all the digits together.
  int tot = 0;
  for (i = 0; i < n; i++) {
    tot += num[i];
  }
  return tot;
}
