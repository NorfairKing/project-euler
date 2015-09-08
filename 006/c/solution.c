#include "stdio.h"
#include "series.h"

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
  int su = sum_naturals(p);
  int suosq = sum_squares(p);
  return su * su - suosq;
}
