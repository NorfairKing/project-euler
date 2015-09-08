#ifndef series_h__
#define series_h__

/* 
 * Returns the sum of the first natural numbers up to a given number.
 * Time: O(1), Space: O(1)
 */
int sum_naturals(int n);

/*
 * The sum of the first n terms of the geometric series \sum_n ar^k
 */
double sum_geometric(double a, double n, double r);

/*
 * Returns the sum of the squares of the natural number up to n.
 * Time: O(1), Space O(1)
 */
int sum_squares(int n);
#endif

