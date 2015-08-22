package projecteuler;

public class Multiple {
  public static int multiples_under(int p, int n) {
    int pdn = p/n - ((p % n == 0) ? 1 : 0);
    return (n * pdn * (pdn + 1)) / 2;
  }
}
