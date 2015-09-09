#include <iostream>

#include "series.h"

int solve(int p);

#ifndef TESTING
int main () {
  int p;
  std::cin >> p;
  std::cout << solve(p) << std::endl;
}
#endif

int solve(int p) {
  int su = sum_naturals(p);
  int suosq = sum_squares(p);
  return su * su - suosq;
}
