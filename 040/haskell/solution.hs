import           Data.List

main :: IO ()
main = readLn >>= print . solve

-- The indices of the asked digits
idx :: Int -> [Int]
idx p = [ 10^x-1 | x <- [0..6] ]

-- Calculate the digits lazily, take out the needed ones, and multiply them.
solve :: Int -> Integer
solve p = product $ map (read . (\n->[n]) . (str !!)) $ idx p
    where str = concatMap show [1..]
