main :: IO ()
main = do
  q <- readLn
  p <- readLn
  print $ solve p q

solve :: Integer -> Integer -> Int
solve p q = length $ filter (> p) [ c n r | n <- [1..q], r <- [1..n]]

-- Calculate the amount of possible combinations.
c :: Integer -> Integer -> Integer
c n r = product [2..n] `quot` ((product [2..r]) * (product [2..(n-r)]))
