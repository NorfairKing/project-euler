import java.math.BigInteger;
import java.util.Scanner;

public class Solution {
  public static void main(String[] args)
  {
    Scanner input = new Scanner(System.in);
    int p = input.nextInt();
    input.nextInt();
    BigInteger res = new BigInteger("0");
    int n = input.nextInt();
    for (int i = 0; i < n; i++) {
      res = res.add(new BigInteger(input.next()));
    }
    System.out.println(res.toString().substring(0, p));
  }
}


