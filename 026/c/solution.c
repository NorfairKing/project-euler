#include <stdio.h>
#include <stdbool.h>

#define EMPTY -1

int solve(int p);
int decimals(int x, int y);

#ifndef TESTING
int main () {
  int p;
  scanf("%d", &p);
  printf("%d\n", solve(p));
  return 0;
}
#endif

int solve(int p) {
  int num = 0;
  int maxlen = 0;
  int d, len, i, x;
  for (d = p; d >= 1; d--) {
    if (maxlen > d) { break; }
    int rems[p]; // d-1 possible remainders

    for (i = 0; i < p; i++) { // Initialise all to predictable constant that will not be used
      rems[i] = EMPTY; 
    }

    x = 1; // Secundary school division
    i = 0; // Next number only depends on the remainder
    while (rems[x] == EMPTY && x != 0) { // as soon as we find it again we'll have the cycle.
      rems[x] = i++;
      x *= 10;
      x %= d;
    }
    
    len = i - rems[x];
    if (len > maxlen) {
      maxlen = len;
      num = d;
    }
  }
  return num;
}
