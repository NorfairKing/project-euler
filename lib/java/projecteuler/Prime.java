package projecteuler;
import java.util.Arrays;

public class Prime {
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
