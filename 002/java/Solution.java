import java.lang.Math;
import java.util.Scanner;

import static projecteuler.Constants.PHI;
import static projecteuler.Constants.PSI;
import static projecteuler.Series.sumGeometric;

public class Solution {
  public static void main (String[] args){
    Scanner in = new Scanner(System.in);
    int p = in.nextInt();
    System.out.println(solve(p));
  }

  public static int solve (int p) {
    double cte = 1/Math.sqrt(5);
    double h = PHI;
    double s = PSI;
    double phi3 = h * h * h;
    double psi3 = s * s * s;
    double n = Math.floor(Math.log(p * Math.sqrt(5))/Math.log(h) + 1/2.0);
    double k = Math.floor(n/3.0);
    double term1 = sumGeometric(phi3, k, phi3);
    double term2 = sumGeometric(psi3, k, psi3);
    return (int) (cte * (term1 + term2));
  }
}
