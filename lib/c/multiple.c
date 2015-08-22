#include "multiple.h"
#include "series.h"

int multiples_under(int p, int n) {
  int pdn = p / n - (p % n == 0);
  return n * sum_naturals(pdn);
}
