#include <stdio.h>

int main () {
    int p = 1000;
    int sum = 0;

    int i;
    for (i = 0; i < p; i++) {
        if (i % 3 == 0 || i % 5 == 0){
            sum += i;
        }
    }

    printf("%d\n",sum);
}

