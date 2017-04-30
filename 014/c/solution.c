#include <stdbool.h>
#include <stdio.h>

#include "factor.h"

int solve(int n);
int collatz_len(int n);
long collatz_next(long n);

#ifndef TESTING
int main() {
  int n;
  scanf("%d\n", &n);  // # of digits to print
  printf("%d\n", solve(n));
  return 0;
}
#endif

int solve(int n) {
  int maxlen = 1;
  int beststart = 1;
  int i;
  for (i = 1; i < n; i++) {
    int len = collatz_len(i);
    if (len > maxlen) {
      maxlen = len;
      beststart = i;
    }
  }
  return beststart;
}

int collatz_len(int n) {
  int len = 0;
  long tmp = n;
  while (tmp != 1) {
    tmp = collatz_next(tmp);
    len++;
  }
  return len;
}

long collatz_next(long n) {
  if (even(n)) {
    return n / 2;
  } else {
    return 3 * n + 1;
  }
}