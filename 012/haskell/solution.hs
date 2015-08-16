import           Control.Monad
import           Data.List

main :: IO ()
main = readLn >>= print . solve

solve :: Int -> Integer
solve n = head [ x | x <- triangles, nr_divisors x >= n]

{-
Triangle numbers are defined recursively but they can be computed explicityly.
1 + 2 + ... + n = (n*(n+1))/2
This means the nth triangle number can be calculated in O(1) time instead of O(n) time.
-}
triangles :: [Integer]
triangles = [(i*(i+1) `div` 2) | i <- [1..]]

{-
Divisors can be calucated in O(n) time by checking every number that is smaller.
We only need to check every number until sqrt(n) for divisors.
We get the other half by dividing.
-}
divisors :: Integral a => a -> [a]
divisors x = firstHalf ++ secondHalf
        where
            firstHalf = 1: (filter ((==0) . rem x) [2 .. sq x])
            secondHalf = reverse [ x `div` i | i <- firstHalf]
            sq = floor . sqrt . fromIntegral

nr_divisors :: Integer -> Int
nr_divisors = length . divisors
