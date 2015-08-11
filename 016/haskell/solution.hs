main = print $ solve $ 2^1000

solve :: Integer -> Int
solve = sum . map (read . (\c -> [c])) . show
