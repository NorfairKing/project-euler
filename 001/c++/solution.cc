#include <iostream>
#include "multiple.h"

int solve(int p);

#ifndef TESTING
int main () {
  int p;
  std::cin >> p;
  std::cout << solve(p) << std::endl;
}
#endif

int solve(int p) {
  int sum = 0;
  sum += multiples_under(p, 3);
  sum += multiples_under(p, 5);
  sum -= multiples_under(p, 15);
  return sum;
}
