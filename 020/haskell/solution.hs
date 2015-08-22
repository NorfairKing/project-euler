main = print $ solve 100

solve :: Integer -> Integer
solve = sumdigits . factorial

factorial :: Integer -> Integer
factorial p = product [2..p]

sumdigits :: Integer -> Integer
sumdigits = sum . map (read . (\c -> [c])) . show

