import java.util.Scanner;

public class Solution {
  public static void main(String[] args)
  {
    Scanner input = new Scanner(System.in);
    int n = input.nextInt();
    System.out.println(solve(n));
  }

  static long solve(int x) {
    int i = 1;
    while (true) {
      long cur = i*(i+1)/2;
      int count = 0;
      for (int j = 1; j*j<=cur; j++) {
        if (cur%j == 0) {
          count += (j*j == cur ? 1 : 2);
        }
      }
      if (count > x) {
        return cur;
      }
      i++;
    }
  }
}


