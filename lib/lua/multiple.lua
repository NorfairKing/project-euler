require "series"

function multiples_under(p, n)
  local pdn = p // n 
  if p % n == 0 then
    pdn = pdn - 1
  end
  return n * sum_naturals(pdn);
end
