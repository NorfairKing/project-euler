import           Data.Char
import           Data.List

main :: IO ()
main = readLn >>= print . solve

-- 1 doesn't count, and there are only 7 numbers that have the
-- property that is described.
solve :: Int -> Int
solve p = (sum . drop 1) [ x | x <- [1..p*9^p], x == (sumpth p x)]

-- Split an integer into its digits
digits :: Int -> [Int]
digits = map digitToInt . show

-- The sum of the pth power of all digits
sumpth :: Int -> Int -> Int
sumpth p = sum . map (^p) . digits
