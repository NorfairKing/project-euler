package projecteuler;

import static projecteuler.Series.sumNaturals;
import static projecteuler.Factor.isFactor;

public class Multiple {
  public static int multiplesUnder(int p, int n) {
    int pdn = p/n - (isFactor(n, p) ? 1 : 0);
    return n * sumNaturals(pdn);
  }
}
