public class Solution {
  public static void main (String[] args){
    System.out.println(solve(20));
  }

  public static int solve (int p) {
    int res = 1;
    for(int i = 2; i <= p; i++) {
      res = lcm(res, i);
    }
    return res;
  }

  public static int gcd (int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }

  public static int lcm (int a, int b) {
    return a / gcd(a, b) * b;
  }
}
