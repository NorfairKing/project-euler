#include <iostream>
#include <cmath>
#include <vector>
#include <stdbool.h>

using namespace std;

vector<bool> sieve(int max) {
    vector<bool> result(max, true);

    result[0] = false;
    result[1] = false;

    for (int i = 2; i < sqrt(max); i++) {
        if (result[i]) {
            for (int j = i*i; j < max; j += i) {
                result[j] = false;
            }
        }
    }
    return result;
}

int solve(int i) {
    vector<bool> primes = sieve(10000);
    int largest = 0;
    int biga = 0;
    int bigb = 0;

    for (int a = -999; a < 1000 ; a++) {
        for (int b = -999; b < 1000; b++) {
            bool valid = true;
            int n = 0;
            int result = 2;
            while (primes[result]) {
                result = n*n + a*n + b;
                if (result < 0) {
                    valid = false;
                    break;
                }
                n++;
            }
            if (valid && n > largest) {
                largest = n;
                biga = a;
                bigb = b;
            }
        }
    }
    return biga * bigb;
}

int main() {
    cout << solve(0) << endl;
}
