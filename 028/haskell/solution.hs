import           Data.List

-- The list [2,4,...(p-1)] represents the gaps between the spiral numbers
-- in every square.
-- These gaps each happen 4 times.
-- There are p squares, but the inner number is not included, so make that (p-1).
indices :: Int -> [Int]
indices p = (0:) $ scanl1 (+) $ concatMap (replicate 4) [2,4..(p-1)]

-- Take the sum of all diagonal numbers
solve :: Int -> Integer
solve p = sum [ l !! i | i <- indices p ]
    where l = [1..]

main :: IO ()
main = print $ solve 1001
