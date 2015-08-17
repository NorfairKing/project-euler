#include "multiple.h"

int multiples_under(int p, int n) {
  int pdn = p / n - (p % n == 0);
  return (n * pdn * (pdn + 1)) / 2;
}
