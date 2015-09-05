#include <vector>
#include "digit.h"

#include "palindrome.h"

bool is_palindrome(int n) {
  std::vector<int> digit = digits(n);
  int s = digit.size();
  for (int i = 0; i < s; ++i) {
    if (digit[i] != digit[s - 1 - i]) {
      return false;
    }
  }
  return true;
}
