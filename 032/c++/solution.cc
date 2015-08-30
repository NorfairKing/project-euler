#include <iostream> 
#include <cmath>
#include <algorithm>
#include <set>
#include "digit.h"

#define BASE 10

int solve(int p);

#ifndef TESTING
int main () {
  int p;
  std::cin >> p;
  std::cout << solve(p) << std::endl;
}
#endif

void scratchDigits(bool digits[BASE], int n) {
  if (n == 0) { return; }
  digits[n % BASE] = true;
  return scratchDigits(digits, n / BASE);
}

bool allTrue(bool digits[BASE]) {
  for (int i = 1; i < BASE; ++i) {
    if (!digits[i]) { return false; }
  }
  return true;
}

int solve(int p) {
  int b = p / 2;
  int sum = 0;
  std::set<int> products;
  bool digits[BASE]; digits[0] = true;
  for (int i = 0; i < pow(BASE, b); ++i) {
    for (int j = i; j < pow(BASE, b); ++j) {
      int k = i * j;

      if (nr_of_digits(i) + nr_of_digits(j) + nr_of_digits(k) != p) { continue; }

      for (int f = 1; f < BASE; ++f) {
        digits[f] = false;
      }

      scratchDigits(digits, i);
      scratchDigits(digits, j);
      scratchDigits(digits, k);

      if (allTrue(digits)) { // found one!
        if(std::find(products.begin(), products.end(), k) != products.end()) {
          continue; // aww, already got it.
        } else {
          sum += k;
        }
        products.insert(k);
      }
    }
  }
  return sum;
}

