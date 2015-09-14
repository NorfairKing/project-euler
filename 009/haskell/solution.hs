main :: IO ()
main = readLn >>= print . solve

solve :: Integer -> Integer
solve p = head [ a * b * c | a <- [1..p], b <- [a..p], c <- [b..p], a + b + c == p, a^2 + b^2 == c^2 ]
