#include <iostream>
#include <vector>

#include "base.h"
#include "digit.h"
#include "factor.h"

int solve(int p);

#ifndef TESTING
int main () {
  int p;
  std::cin >> p;
  std::cout << solve(p) << std::endl;
}
#endif

int solve(int p) {
  int len = 2 * p;
  int lo = pow(BASE, p - 1);
  int hi = pow(BASE, p);
  std::vector<int> digits(len);
  for (int i = 0; i < hi; i++) {
    for (int j = 0, num = i; j < p; ++j, num /= BASE){
      int d = (BASE - 1) - (num % BASE);
      digits[p - j - 1] = d;
      digits[p + j] = d;
    }

    int palindrome = from_digits(digits);

    for (int j = hi - 1; j >= lo; --j){
      int q = palindrome / j;
      int m = palindrome % j;
      if (m == 0 && q < hi && q > lo) {
        return palindrome;
      }
    }
  }
  return -1;
}
