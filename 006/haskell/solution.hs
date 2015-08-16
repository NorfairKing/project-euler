main :: IO ()
main = readLn >>= print . solve

solve :: Integer -> Integer
solve p = ((p*(p+1) `div` 2)^2) - ((p*(p+1)*(2*p+1)) `div` 6)
