#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "factors.h"
#include "digit.h"

int solve(int p);

#ifndef TESTING
int main () {
    printf("%d\n", solve(3));
    return 0;
}
#endif

int solve(int p) {
    int len = 2*p; int hi = pow(10, p); int lo = pow(10, p-1);
    int digits[len];
    int i;
    for (i = 0; i < hi; i++) {
        int j;
        int num = i;
        for (j = p - 1; j >= 0; j--){
            digits[j] = 9 - (num % 10);
            num /= 10;
        }

        for (j = 0; j < p; j++) { // Fill second half
            digits[len-1-j] = digits[j];
        }

        int palindrome = from_digits(digits, len);
        
        for (j = hi - 1; j >= lo; j--){
            int q = palindrome / j;
            int m = palindrome % j;
            if (m == 0 && q < hi && q > lo) {
                return palindrome;
            }
        }
    }
    return -1;
}
