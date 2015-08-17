import java.util.Scanner;
import projecteuler.Multiple;

public class Solution {
  public static void main (String[] args){
    Scanner in = new Scanner(System.in);
    int p = in.nextInt();
    System.out.println(solve(p));
  }

  public static int solve (int p) {
    int sum = 0;
    sum += Multiple.multiples_under(p, 3);
    sum += Multiple.multiples_under(p, 5);
    sum -= Multiple.multiples_under(p, 15);
    return sum;
  }
}
