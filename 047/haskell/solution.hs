import           Data.List (genericLength, group)
import           Primes    (primeFactorisation)
main :: IO ()
main = readLn >>= print . solve

solve :: Integer -> Integer
solve n = go hackstack needle [1..] 1
  where
    needle = replicate (fromIntegral n) n
    hackstack = nbsPrimeFactors
    go :: [Integer] -> [Integer] -> [Integer] -> Integer -> Integer
    go _ [] _ ix = ix
    go (h:hs) (n:ns) (i:is) ix | h == n = go hs ns is ix
                               | h /= n = go hs needle is (i+1)

nbsPrimeFactors :: [Integer]
nbsPrimeFactors = map (genericLength . distinctPrimeFactors) [1..]

distinctPrimeFactors :: Integer -> [Integer]
distinctPrimeFactors = nubOrdered . primeFactorisation

nubOrdered :: Eq a => [a] -> [a]
nubOrdered = map head . group
