main :: IO ()
main = do
  p <- readLn
  a <- readLn
  b <- readLn
  print $ solve a b p

solve :: Integer -> Integer -> Integer -> Integer
solve a b p = (a * 2^b + 1) `mod` 10 ^ p
