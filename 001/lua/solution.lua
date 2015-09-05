function solve(p)
  local sum = 0
  for i = 1, (p - 1) do
    if (i % 5 == 0 or i % 3 == 0) then
      sum = sum + i
    end
  end
  return sum
end

p = io.read()
print(solve(p))
