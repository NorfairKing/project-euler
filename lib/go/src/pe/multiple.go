package pe

func MultiplesUnder(p int, n int) int {
  var pdn int = p / n
  if (p % n == 0) { pdn-- }
  return n * SumNaturals(pdn)
}
