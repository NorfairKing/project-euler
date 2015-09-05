import java.util.Scanner;

import static projecteuler.Base.BASE;
import static projecteuler.Palindrome.isPalindrome;

public class Solution {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    int n = input.nextInt();
    System.out.println(solve(n));
  } 

  static int solve(int n) {
    int res = 0;
    for(int i = (int) Math.pow(BASE, n - 1); i < Math.pow(BASE, n); i++) {
      for(int j = (int) Math.pow(BASE, n - 1); j < Math.pow(BASE, n); j++) {
        if(isPalindrome(i * j)) {
          res = Math.max(res, i*j);
        }
      }
    }
    return res;
  }
}
