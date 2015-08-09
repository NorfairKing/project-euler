import           Data.List

-- Sum n terms, here n = 1000
n :: Integer
n = 1000

-- Take the last p digits, here p = 10
p :: Integer
p = 10

-- Explicitly calculate the sum and get the last p digits by performing a modulo operation.
solve :: Integer
solve = (sum [ a^a | a <- [1..n]]) `mod` 10^p

main :: IO ()
main = print solve
