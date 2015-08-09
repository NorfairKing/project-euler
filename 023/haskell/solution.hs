import Data.List

-- Upper limit for the numbers that can be written as the sum of two abundant numbers 
p = 28123

-- The proper divisors of a given integer.
divisors :: Integral a => a -> [a]
divisors x = (nub.init) $ firstHalf ++ secondHalf
        where
            firstHalf = 1: (filter ((==0) . rem x) [2 .. sq x])
            secondHalf = reverse [ x `div` i | i <- firstHalf]
            sq = floor . sqrt . fromIntegral

-- Whether a number is abundant.
isAbundant x = (sum . divisors) x > x

-- The list of all abundants smaller than p.
abundants = filter isAbundant [1..p]

-- Whether a number is the sum of two abundant numbers
isSumOfTwoAbundants n = any (\x -> isAbundant (n - x)) $ takeWhile (<n) abundants

-- The list of numbers for which it's not possible to be written as a sum of two abundant numbers.
notPossible = filter (not . isSumOfTwoAbundants) [1..p]

solve :: Int
solve = sum $ notPossible

-- IO
main :: IO ()
main = do
    print solve        
