package projecteuler;

import java.lang.Math;

public class Series {

  public static int sumNaturals(int n) {
    return (n * (n + 1)) / 2;
  }

  public static double sumGeometric(double a, double n, double r) {
    return a * (1 - Math.pow(r, n)) / (1 - r);
  }
}
