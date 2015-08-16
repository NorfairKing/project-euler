#include <stdio.h>

int solve(int p);
int multiples_under(int p, int n);

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

int multiples_under (int p, int n){
  int pdn = p / n - (p % n == 0);
  return (n * pdn * (pdn + 1)) / 2;
}
