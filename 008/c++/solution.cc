#include <iostream>
#include <vector>

long solve(int k, std::vector<char> ds);

#ifndef TESTING
int main() {
  int k, n;
  std::cin >> k;
  std::cin >> n;
  std::vector<char> ds(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> ds[i];
    ds[i] -= '0';
  }
  std::cout << solve(k, ds) << std::endl;
}
#endif

long solve(int k, std::vector<char> ds) {
  long maxproduct = 0;
  long product = 1;
  int left = k; // Starters left
  int n = ds.size();
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
