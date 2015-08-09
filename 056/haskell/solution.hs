import Data.List
import Data.Char

-- p is the limit for a and b
p :: Integer
p = 100

-- Calculate every number in the sequence
nrs :: [Integer]
nrs = [ a^b | a <- [1..p], b <- [1..p]]

-- Split a number into its digits
digits :: Integer -> [Int]
digits = (map digitToInt) . show

-- Calculate the sum of the digits of a number
digitalSum :: Integer -> Int
digitalSum = sum . digits

solve :: Int
solve = maximum [ digitalSum x | x <- nrs]

-- IO
main :: IO ()
main = do
    putStrLn $ show solve        
