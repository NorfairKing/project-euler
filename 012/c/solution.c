#include <stdio.h>
#include <stdbool.h>

#include "factor.h"

int solve(int n);

#ifndef TESTING
int main () {
  int n;
  scanf("%d\n", &n);
  printf("%d\n", solve(n));
  return 0;
}
#endif

int solve(int n) {
  int cur = 0;
  while(1) {
    int triang = (cur * (cur + 1)) / 2;
    int numdiv = nr_divisors(triang);
    if (numdiv >= n) {
      return triang;
    }
    cur++;
  }
}
