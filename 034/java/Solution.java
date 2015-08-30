public class Solution {
  static int[] facts = new int[]{1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
  public static void main(String[] args) {
    System.out.println(solve());
  }

  static int solve() {
    cacheFactorials(10);
    int res = 0;
    int count = 0;
    int i = 3;
    while (count < 2) {
      if (i == go(i)) {
        res += i;
        count++;
      }
      i++;
    }
    return res;
  }

  static void cacheFactorials(int n) {
    facts[0] = 1;
    for (int i = 1; i < n; i++) {
      facts[i] = facts[i-1] * i;
    }
  }

  static int go(int n) {
    int res = 0;
    while(n > 0) {
      res += facts[n%10];
      n /= 10;
    }
    return res;
  }
}
