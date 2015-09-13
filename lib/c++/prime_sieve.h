#ifndef prime_sieve_h__
#define prime_sieve_h__

#include <vector>

class PrimeSieve {
  private:
    std::vector<bool> sieve;

    void resize(size_t n);
    void resieve(size_t from, size_t to, size_t jstart);

  public:
    PrimeSieve();
    PrimeSieve(int n);

    bool is_prime(int n);
    bool operator[] (const int nIndex);
};

#endif
