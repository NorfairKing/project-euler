#include <stdio.h>

int solve (int p);
int multiples_under(int p, int n);

#ifndef TESTING
int main () {
    printf("%d\n", solve(1000));
}
#endif

int solve(int p) {
    int sum = 0;

    sum += multiples_under(p, 3);
    sum += multiples_under(p, 5);
    sum -= multiples_under(p, 15);

    return sum;
}

int multiples_under(int p, int n) {
    int sum = 0;
    int i;
    for (i = 0; i < p; i += n ) {
        sum += i;
    }
    return sum;
}
