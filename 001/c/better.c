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

int solve(int p) {
  int sum = 0;

  sum += multiples(p, 3);
  sum += multiples(p, 5);
  sum -= multiples(p, 15);

  return sum;
}

int multiples(int p, int n) {
  int sum = 0;
  int i;
  for (i = 0; i < p; i += n ) {
    sum += i;
  }
  return sum;
}
