#include "multiple.h"
#include "factor.h"
#include "series.h"

// This is used in multiple.tex
int multiples_under(int p, int n) {
  int pdn = p / n - divides(n, p);
  return n * sum_naturals(pdn);
}
