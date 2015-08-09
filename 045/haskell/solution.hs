import           Data.List

{-
    Let T be the triangle numbers and H the hexagonal numbers.
    H is a subset of T, so we can ignore T.
-}

pentagonalNrs, hexagonalNrs :: Integer -> [Integer]
pentagonalNrs p = [ (n*(3*n-1)) `quot` 2 | n <- [165..p]]
hexagonalNrs  p = [ (n*(2*n-1))          | n <- [143..p]]

solve :: Integer -> Integer
solve p = head $ filter (/= 40755) $ intersect he pe
    where
        pe = pentagonalNrs p
        he = hexagonalNrs p

-- IO
main :: IO ()
main = print $ solve 50000
