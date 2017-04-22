#include <stdbool.h>

#include "digit.h"
#include "palindrome.h"

/*
 * Checks whether a given number is a palindrome, that is, can be read in the
 * same way forwards and backwards.
 */
bool is_palindrome(int n) {
  int nr = nr_of_digits(n);
  int i;
  for (i = 0; i < nr / 2; i++) {
    if (digit(i, n) != digit(nr - 1 - i, n)) {
      return false;
    }
  }
  return true;
}
