#include <stdio.h>

int solve (int p);

#ifndef TESTING
int main () {
  int p;
  scanf("%d", &p);
  printf("%d\n", solve(p));
}
#endif

int solve(int p) {
  int sum = 0;

  int i;
  for (i = 0; i < p; i++) {
    if (i % 3 == 0 || i % 5 == 0){
      sum += i;
    }
  }
  return sum;
}
