import java.util.Scanner;
import java.util.Arrays;

public class Solution {
  public static void main(String[] args)
  {
    Scanner input = new Scanner(System.in);
    int n = input.nextInt();
    System.out.println(solve(n));
  }

  static long solve(int n) {
    boolean[] sieve = new boolean[n+1];
    Arrays.fill(sieve,  true);
    long res = 0;
    sieve[0] = sieve[1] = false;
    for(int i = 2; i<=n; i++)
    {
      if(sieve[i])
      {
        res += i;
        for(long j = (long)i*i; j <= n; j += i)
          sieve[(int)j] = false;
      }
    }
    return res;
  }
}

