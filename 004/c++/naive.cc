#include <cmath>
#include <iostream>

#include "base.h"
#include "digit.h"
#include "palindrome.h"

int solve(int);

int main() {
  int p;
  std::cin >> p;
  std::cout << solve(p) << std::endl;
}

int solve (int n) {
  int res = 0;
  for(int i = pow(BASE, n - 1); i < pow(BASE, n); ++i) {
    for(int j = pow(BASE, n - 1); j < pow(BASE, n); ++j) {
      if(is_palindrome(i * j)) {
        res = std::max(res, i*j);
      }
    }
  }
  return res;
}
