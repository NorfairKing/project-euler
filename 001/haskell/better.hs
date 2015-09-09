import           Multiple

main :: IO ()
main = readLn >>= print . solve

-- [001/explanation.tex]
solve :: Integer -> Integer
solve p = f 3 + f 5 - f 15
  where f q = sum [q, 2 * q  ..  p - 1]
