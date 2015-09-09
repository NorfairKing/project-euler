#include "series.h"
#include "math.h"

// This is being used in series.tex
int sum_naturals(int n) {
  return (n * (n + 1)) / 2;
}

// This is being used in series.tex
double sum_geometric(double a, double n, double r) {
  return a * (1 - pow(r, n)) / (1 - r);
}

int sum_squares(int n) {
  return (n * (n + 1) * (2 * n + 1)) / 6;
}
