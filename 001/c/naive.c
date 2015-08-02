#include <stdio.h>

int solve ();

#ifndef TESTING
int main () {
    printf("%d\n", solve(1000));
}
#endif

int solve(int p) {
    int sum = 0;

    int i;
    for (i = 0; i < p; i++) {
        if (i % 3 == 0 || i % 5 == 0){
            sum += i;
        }
    }
    return sum;
}
