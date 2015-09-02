module Primes where

import           Factor

primes :: [Integer]
primes = sieve [2..]
  where sieve (p:xs) = p : sieve [ x | x <- xs, x `rem` p /= 0]

isPrime :: Integer -> Bool
isPrime n = all (\p -> n `rem` p /= 0) [2.. sq n]
  where sq = ceiling . sqrt . fromInteger

-- [primes.tex]
primeFactorisation :: Integer -> [Integer]
primeFactorisation n = go primes n
  where
    go :: [Integer] -> Integer -> [Integer]
    go _ 1 = []
    go (p:ps) n     | p `isFactorOf` n = p : go (p:ps) (n `div` p)
                    | otherwise        = go ps n

