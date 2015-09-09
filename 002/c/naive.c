#include <stdio.h> 
#include "factor.h"

int solve(int p);

#ifndef TESTING
int main () {
  int p;
  scanf("%d", &p);
  printf("%d\n", solve(p));
  return 0;
}
#endif

// [002/explanation.tex]
int solve (int p) {
    int sum = 0;

    int snd = 0;
    int fst = 1;
    int cur = 1;

    while (cur <= p) {
        if (even(cur)) {
            sum += cur;
        }

        snd = fst;
        fst = cur;
        cur = snd + fst;
    }

    return sum;
}
