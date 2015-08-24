#include "series.h"
#include "math.h"

int sum_naturals(int n) {
  return (n * (n + 1)) / 2;
}

double sum_geometric(double a, double n, double r){
  return a * (1 - pow(r, n)) / (1 - r);
}
