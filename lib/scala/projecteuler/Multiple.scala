package projecteuler

object Multiple {
  def multiplesUnder(p: Int, n: Int): Int = {
    val pdn = p/n - (if(p % n == 0) 1 else 0)
    (n * pdn * (pdn + 1)) / 2
  }
}
