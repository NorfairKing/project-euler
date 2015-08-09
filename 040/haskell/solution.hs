import           Data.List

-- The indices of the asked digits
p :: [Int]
p = [ 10^x-1 | x <- [0..6] ]

-- A utility read function, to make things nicer.
rd :: String -> Integer
rd x  = read x :: Integer

-- Calculate the digits lazily, take out the needed ones, and multiply them.
solve :: Integer
solve = product $ map (rd . (\n->[n]) . (str !!)) p
    where str = concatMap show [1..]

-- IO
main :: IO ()
main = print solve
