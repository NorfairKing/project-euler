#include <stdio.h>
#include <stdbool.h>

#include "factors.h"

int solve(int p);
bool all_divisible(int p, int n);

#ifndef TESTING
int main () {
  int p;
  scanf("%d", &p);
  printf("%d\n", solve(p));
  return 0;
}
#endif

int solve(int p) {
  int i;
  for (i = 1;;i++) {
    if (all_divisible(p, i)){
      return i;
    }
  }
}

bool all_divisible(int p, int n) {
  int i;
  for (i = 2; i <= p; i++) {
    if (!is_evenly_divisible_by(n, i)){
      return false;
    }
  }
  return true;
}
