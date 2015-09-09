#include <stdio.h>
#include <stdbool.h>

long solve(int k, int n, char ds[]);

#ifndef TESTING
int main() {
  int k, n;
  scanf("%d\n", &k);
  scanf("%d\n", &n);
  char ds[n];
  int i;
  for (i = 0; i < n; ++i) {
    ds[i] = getchar() - '0';
  }
  printf("%ld\n", solve(k, n, ds));
}
#endif

long solve(int k, int n, char ds[n]) {
  long maxproduct = 0;
  long product = 1;
  int left = k; // Starters left
  int i;
  for (i = 0; i < n; ++i) {
    // If we find a zero, start over because the product will be 0.
    if (ds[i] == 0) { 
      left = k;
      product = 1;
      continue;
    }
    // If we still have starters to multiply, do that first
    if (left > 0) {
      product *= ds[i];
      left--;
      // If all starters have been multiplied, start considering the product
      if (left == 0) {
        if (product > maxproduct) {
          maxproduct = product;
        }
      }
    } else {
      // divide out the first one and multiply in the new one 
      product /= ds[i-k];
      product *= ds[i];
      if (product > maxproduct) {
        maxproduct = product;
      }
    }
  }
  return maxproduct;
}
