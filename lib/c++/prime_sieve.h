#ifndef prime_sieve_h__
#define prime_sieve_h__

#include <vector>

class prime_sieve {
  private:
    std::vector<bool> prime;
    int upto;

    void size_up(int n);

  public:
    prime_sieve();
    prime_sieve(int n);

    bool is_prime(int n);
    bool operator[] (const int nIndex);
};

#endif
