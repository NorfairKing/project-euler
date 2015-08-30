import java.util.Scanner;

public class Solution {
  public static void main(String[] args)
  {
    Scanner input = new Scanner(System.in);
    int n = input.nextInt();
    System.out.println(solve(n));
  }

  static int solve(int n) {
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < n; j++) {
        int sq = i*i + j*j;
        int c = (int)(.5 + Math.sqrt(sq));
        if (Math.abs(c - Math.sqrt(sq)) < 1e-9 && i + j + c == n) {
          return i*j*c;
        }
      }
    }
    return -1;
  }
}
