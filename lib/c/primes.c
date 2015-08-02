#include <stdbool.h>
#include "factors.h"

/*
 * Tests whether a given long is prime.
 * Works in O(sqrt(n)) time.
 * Does not work on numbers smaller than 2
 */
bool is_prime (long n) {
    if (n == 1){ return false; }
    int i;
    for (i = 2; i*i <= n; i++) {
        if (is_factor_l(i, n)){
            return false;
        }
    }
    return true;
}


/*
 * Fills an array of booleans with indications of which numbers are prime.
 * Works in O(sqrt(n)) time and is correct up to the given n.
 */
void sieve(bool nums[], int n){
    int i, j;
    nums[0] = false;
    nums[1] = false;
    for (i = 2; i < n; i++){
        nums[i] = true;
    }  
    for (i = 2; i*i < n; i++){
        if (nums[i]) {
            for (j = i+i; j < n; j += i){
                nums[j] = false;
            }
        }
    }       
}
