require "multiple"

function solve(p)
  return multiples_under(p, 3)
       + multiples_under(p, 5)
       - multiples_under(p, 15)
end

p = io.read()
print(math.floor(solve(p)))
