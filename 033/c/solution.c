#include <stdio.h>
#include <stdbool.h>
#include "base.h"
#include "digit.h"

int solve(int p);

#ifndef TESTING
int main() {
  int p;
  scanf("%d", &p);
  printf("%d\n", solve(p));
}
#endif

bool simplify(int id, int jd, int idigit[id], int jdigit[jd], bool imask[id], bool jmask[jd]) {
  bool simplified = false;
  int a, x, y;
  for (a = 0; a < BASE; ++a) {
    for (x = 0; x < id; ++x) {
      if (!imask[x]) { continue; }
      for (y = 0; y < jd; ++y) {
        if (!jmask[y]) { continue; }

        if (idigit[x] == jdigit[y]) {
          simplified = true;
          imask[x] = false;
          jmask[y] = false;
        }
      }
    }
  }
  return simplified;
}

int from_digits_with_mask(int nrd, int digit[], bool mask[]) {
  int j; int num = 0, p = 0;
  for (j = nrd-1; j >= 0; --j){
    if (mask[j]) {
      num += digit[j] * pow(10, p++);
    }
  }
  return num;
}

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int solve(int p) {
  int num = 1;
  int denom = 1;

  int i, j, k;
  for (i = BASE; i < pow(BASE, p); ++i) {
    for (j = i + 1; j < pow(BASE, p); ++j) {
      if (i % BASE == 0 || j % BASE == 0) { continue; }
      int id = nr_of_digits(i);
      int jd = nr_of_digits(j);

      int idigit[id];
      int jdigit[jd];

      fill_digits(idigit, id, i);
      fill_digits(jdigit, jd, j);

      bool imask[id];
      bool jmask[jd];

      for (k = 0; k < id; ++k) { imask[k] = true; }
      for (k = 0; k < jd; ++k) { jmask[k] = true; }

      if (simplify(id, jd, idigit, jdigit, imask, jmask)) {
        int newi = from_digits_with_mask(id, idigit, imask);
        int newj = from_digits_with_mask(jd, jdigit, jmask);
        if (newi == 0 || newj == 0) { continue; }
        if (i * newj == j * newi) {
          num *= newi;
          denom *= newj;
        }
      }
    }
  }
  
  return denom / gcd(num, denom);
}
