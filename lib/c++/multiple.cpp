#include "multiple.h"
#include "series.h"
#include "factor.h"

int multiples_under(int p, int n) {
  int pdn = p / n - divides(n, p);
  return n * sum_naturals(pdn);
}
