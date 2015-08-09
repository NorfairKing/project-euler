-- We want the combinations greater than p.
-- q is the limit for n.
p,q :: Integer
p = 10^6
q = 100

-- Calculate the amount of possible combinations.
c :: Integral a => a -> a -> a
c n r = (product [2..n]) `quot` ((product [2..r])*(product [2..(n-r)]))

solve :: Int
solve = length $ filter (> p) [ c n r | n <- [1..q], r <- [1..n]]

main :: IO ()
main = print solve
