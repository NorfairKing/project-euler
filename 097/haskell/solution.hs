-- We want the last p digits, so p = 10.
p :: Integer
p = 10

-- The number.
n :: Integer
n = (28433 * 2^7830457) + 1

solve :: Integer
solve = n `mod` 10^p

-- IO
main :: IO ()
main = print solve
