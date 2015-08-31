import java.util.Scanner;
import static projecteuler.Multiple.multiplesUnder;

public class Solution {
  public static void main (String[] args){
    Scanner in = new Scanner(System.in);
    int p = in.nextInt();
    System.out.println(solve(p));
  }

  public static int solve (int p) {
    int sum = 0;
    sum += multiplesUnder(p, 3);
    sum += multiplesUnder(p, 5);
    sum -= multiplesUnder(p, 15);
    return sum;
  }
}
