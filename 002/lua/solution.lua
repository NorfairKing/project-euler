require "constant"
require "series"

function solve(p)
  cte = 1/math.sqrt(5)
  h = phi
  s = psi
  phi3 = h * h * h
  psi3 = s * s * s
  n = math.floor(math.log(p * math.sqrt(5))/math.log(h) + 1/2.0)
  k = math.floor(n/3.0)
  term1 = sum_geometric(phi3, k, phi3)
  term2 = sum_geometric(psi3, k, psi3)
  return math.floor(cte * (term1 + term2))
end

p = io.read()
print(solve(p))
