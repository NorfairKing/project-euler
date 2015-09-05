import java.util.Scanner;

import static projecteuler.Factor.isFactor;
import static projecteuler.Prime.isPrime;

public class Solution {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    long p = input.nextLong();
    System.out.println(solve(p));
  }

  static int solve(long p) {
    int f = 2;
    while (p > 1) {
      if (isPrime(f) && p % f == 0) {
        p /= f;
        continue;
      }
      f++;
    }
    return f;
  }
}
