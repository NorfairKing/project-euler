{-
    I will brute force the problem here.
    In problem 67, I will find an efficient solution.
-}

import           Control.Monad

-- Find all paths in a triangle
paths :: [[a]] -> [[a]]
paths [] = []
paths [[x]] = [[x]]
paths triangle = map (first:) $ concatMap paths (subtriangles triangle)
        where
            first = (head . head) triangle

-- Sharpen a trapezium at a given index.
-- This function (given 1) turns
-- [[1,2,3],[4,5,6,7],[8,9,10,11,12]]
-- into
-- [[2],[5,6],[9,10,11]
sharpen :: [[a]] -> Int -> [[a]]
sharpen trapezium index = map sh trapezium
        where
            sh ll = (firsts . lasts) ll
            firsts ll = take ((length ll) - (length (head trapezium)) + index + 1) ll
            lasts ll = drop index ll

-- Construct the two subtriangles of a given triangle
subtriangles :: [[t]] -> [[[t]]]
subtriangles [] = []
subtriangles [[x]] = [[[x]]]
subtriangles triangle = map (sharpen (tail triangle)) [0,1]

-- Get the maximum of the sums of all paths
solve :: [[Int]] -> Int
solve triangle = maximum $ map sum (paths triangle)

-- IO
rd :: String -> Int
rd x  = read x :: Int

getInt :: IO Int
getInt = read `liftM` getLine :: IO Int

getInts :: IO [Int]
getInts = do
        line <- getLine
        return (map rd $ words line)

main :: IO ()
main = do
    n <- getInt
    triangle <- replicateM n getInts
    putStrLn $ show (solve triangle)
