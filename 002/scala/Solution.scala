import scala.math.sqrt
import scala.math.log
import scala.math.pow
import scala.math.floor

import projecteuler.Constants.PHI
import projecteuler.Constants.PSI
import projecteuler.Series.sumGeometric

object Solution {
  def main(args: Array[String]) {
    val p : Int = readInt()
    println(solve(p))
  }

  def solve(p: Int): Int = {
    val cte = 1/sqrt(5)
    val phi3 = PHI * PHI * PHI
    val psi3 = PSI * PSI * PSI
    val n = floor(log(p * sqrt(5))/log(PHI) + 1/2.0)
    val k = floor(n/3.0)
    val term1 = sumGeometric(phi3, k, phi3)
    val term2 = sumGeometric(psi3, k, psi3)
    (cte * (term1 + term2)).toInt
  }
}
