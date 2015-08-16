import           Text.Printf (printf)

main :: IO ()
main = do
  p <- readLn
  n <- readLn
  print $ solve p n

-- Explicitly calculate the sum and get the last p digits by performing a modulo operation.
solve :: Integer -> Integer -> Integer
solve p n = (sum [ a^a | a <- [1..n]]) `mod` 10^p
