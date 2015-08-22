import           Data.Char
import           Data.List

main :: IO ()
main = readLn >>= print . solve

solve :: Integer -> Int
solve p = maximum [ digitalSum x | x <- nrs p ]

-- Calculate every number in the sequence
nrs :: Integer -> [Integer]
nrs p = [ a^b | a <- [1..p], b <- [1..p]]

-- Split a number into its digits
digits :: Integer -> [Int]
digits = map digitToInt . show

-- Calculate the sum of the digits of a number
digitalSum :: Integer -> Int
digitalSum = sum . digits

