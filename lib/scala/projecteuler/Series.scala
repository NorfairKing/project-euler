package projecteuler

object Series {
  def sumNaturals(n: Int): Int = {
    return (n * (n + 1)) / 2
  }

  def sumGeometric(a: Double, n: Double, r: Double): Double = {
    return a * (1 - Math.pow(r, n)) / (1 - r);
  }
}
