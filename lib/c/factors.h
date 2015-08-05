#ifndef factors_h__
#define factors_h__

#include <stdbool.h>

bool even(int n);
bool even_l(int n);

bool odd(int n);
bool odd_l(long n);

bool is_factor(int n, int m);
bool is_factor_l(long n, long m);

bool is_evenly_divisible_by(int n, int m);
bool is_evenly_divisible_by_l(long n, long m);

bool divides(int n, int m);
bool divides_l(long n, long m);

int nr_divisors(int n);
void fill_nr_divisors(int divs[], int n);

int sum_divisors(int n);
void fill_sum_divisors(int divs[], int n);

#endif
