#include "prime_sieve.h"

#define PRIME_SIEVE_DEFAULT_CAPACITY 5

prime_sieve::prime_sieve()
    : prime_sieve::prime_sieve(PRIME_SIEVE_DEFAULT_CAPACITY) {}

prime_sieve::prime_sieve(int n) {}

prime_sieve::~prime_sieve() {}

void prime_sieve::resize(int n) {}

prime_sieve::is_prime(int n) { return false; }

int &prime_sieve::operator[](const int n) { return is_prime(n); }
