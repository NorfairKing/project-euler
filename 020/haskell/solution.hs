main :: IO ()
main = readLn >>= print . solve

solve :: Integer -> Integer
solve = sumdigits . factorial

factorial :: Integer -> Integer
factorial p = product [2..p]

sumdigits :: Integer -> Integer
sumdigits = sum . map (read . (\c -> [c])) . show

