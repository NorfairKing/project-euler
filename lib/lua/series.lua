function sum_naturals(n)
  return (n * (n + 1)) // 2
end

function sum_geometric(a, n, r)
  return a * (1 - math.pow(r, n)) / (1 - r)
end
