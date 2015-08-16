import           Data.Char
import           Data.List

-- Split an integer into its digits
digits = (map digitToInt) . show

-- The sum of the pth power of all digits
fac n = product [1..n]

-- Take the sum of the factorial of each digit
sumfacdigits = sum . (map fac) . digits

-- 1 and 2 don't count, and there are only 2 numbers that have the
-- property that is described.
solve = (sum . take 2 . drop 2) [ x | x <- [1..], x == (sumfacdigits x)]

-- IO
main :: IO ()
main = print solve
