main :: IO ()
main = readLn >>= print . solve

solve :: Integer -> Int
solve = sum . map (read . (\c -> [c])) . show . (2^)
