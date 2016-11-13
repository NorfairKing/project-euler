import java.util.Scanner;

public class Solution {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int p = in.nextInt();
    System.out.println(solve(p));
  }

  public static int solve(int p) {
    int sumsq = 0;
    int sqsum = 0;
    for (int i = 0; i <= p; ++i) {
      sumsq += i * i;
      sqsum += i;
    }

    sqsum *= sqsum;
    return sqsum - sumsq;
  }
}
