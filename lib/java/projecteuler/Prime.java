package projecteuler;

import java.util.Arrays;
import static projecteuler.Factor.isFactor;

public class Prime {
  public static boolean isPrime(int n) {
    if (n <= 1) { return false; }
    for (int i = 2; i * i <= n; i++) {
      if (isFactor(i, n)) {
        return false;
      }
    }
    return true;
  }

  public static boolean[] sieve(int n) {
    boolean[] sieve = new boolean[n+1];
    Arrays.fill(sieve, true);
    sieve[0] = sieve[1] = false;
    for(int i = 2; i<=n; i++)
    {
      if(sieve[i])
      {
        for(long j = (long)i*i; j <= n; j += i) {
          sieve[(int)j] = false;
        }
      }
    }
    return sieve;
  }
}
