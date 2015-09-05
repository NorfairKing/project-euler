package projecteuler

import projecteuler.Series.sumNaturals

object Multiple {
  def multiplesUnder(p: Int, n: Int): Int = {
    val pdn = p/n - (if(p % n == 0) 1 else 0)
    return n * sumNaturals(pdn)
  }
}
