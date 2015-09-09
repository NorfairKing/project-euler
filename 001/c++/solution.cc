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
  return multiples_under(p, 3)
       + multiples_under(p, 5)
       - multiples_under(p, 15);
}
