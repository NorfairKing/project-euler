#include <stdio.h>

int solve (int p);
int multiples(int p, int n);

#ifndef TESTING
int main () {
  int p;
  scanf("%d", &p);
  printf("%d\n", solve(p));
}
#endif

// [001/explanation.tex]
int solve(int p) {
  return multiples(p, 3)
       + multiples(p, 5)
       - multiples(p, 15);
}

int multiples(int p, int n) {
  int sum = 0;
  int i;
  for (i = 0; i < p; i += n ) {
    sum += i;
  }
  return sum;
}
