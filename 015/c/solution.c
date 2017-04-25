#include <stdbool.h>
#include <stdio.h>

long solve(int n);

#ifndef TESTING
int main() {
  int n;
  scanf("%d\n", &n);  // # of digits to print
  printf("%ld\n", solve(n));
  return 0;
}
#endif

long solve(int n) {
  long options[n + 1][n + 1];

  options[0][0] = 1;
  int i;
  for (i = 1; i <= n; i++) {
    options[i][0] = 1;
    options[0][i] = 1;
  }

  int j;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      options[i][j] = options[i - 1][j] + options[i][j - 1];
    }
  }
  return options[n][n];
}
