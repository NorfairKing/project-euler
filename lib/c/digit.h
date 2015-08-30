#ifndef digit_h__
#define digit_h__

#include <math.h>
#include <stdbool.h>

int nr_of_digits(int n);
int digit(int n, int p);
int from_digits(int digit[], int n);
void fill_digits(int digit[], int nrd, int n);

#endif
