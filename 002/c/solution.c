#include <stdio.h>

int solve(int p);

#ifndef TESTING
int main () {
    printf("%d\n", solve(4000000));
}
#endif

int solve (int p) {
    int sum = 0;

    int snd = 0;
    int fst = 1;
    int cur = 1;

    while (cur <= p){
        if (cur & 1){
            sum += cur;
        }

        snd = fst;
        fst = cur;
        cur = snd + fst;
    }

    return sum;
}
