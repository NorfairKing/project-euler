import java.util.Scanner;
import static projecteuler.Multiple.multiplesUnder;

public class Solution {
  public static void main (String[] args){
    Scanner in = new Scanner(System.in);
    int p = in.nextInt();
    System.out.println(solve(p));
  }

  public static int solve (int p) {
    return multiplesUnder(p, 3)
         + multiplesUnder(p, 5)
         - multiplesUnder(p, 15);
  }
}
