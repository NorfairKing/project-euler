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

// [001/explanation.tex]
int solve(int p) {
  return multiples_under(p, 3)
       + multiples_under(p, 5)
       - multiples_under(p, 15);
}
