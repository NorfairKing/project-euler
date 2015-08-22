#include <stdio.h>
#include "multiple.h"

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
  int sum = 0;

  sum += multiples_under(p, 3);
  sum += multiples_under(p, 5);
  sum -= multiples_under(p, 15);

  return sum;
}
