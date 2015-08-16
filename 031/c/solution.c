#include <stdio.h>

long solve(int p);
long go (int amount, int first);

#ifndef TESTING
int main () {
    printf("%ld\n", solve(200));
    return 0;
}
#endif

#define NUMCOINS 8
static int coins[NUMCOINS] = {1, 2, 5, 10, 20, 50, 100, 200};

long solve(int p) {
  return go(p, 0);
}

long go(int amount, int first) {
  if (first == NUMCOINS) { return amount == 0 ? 1 : 0; }
  int cur = coins[first];
  int res = 0, i;
  for (i = 0; i * cur <= amount; i++) {
    res += go(amount - i*cur, first + 1);
  }
  return res;
}
