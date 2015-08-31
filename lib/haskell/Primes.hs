module Primes where

primes :: [Integer]
primes = sieve [2..]
  where sieve (p:xs) = p : sieve [ x | x <- xs, x `rem` p /= 0]

isPrime :: Integer -> Bool
isPrime n = all (\p -> n `rem` p /= 0) [2.. sq n]
  where sq = ceiling . sqrt . fromInteger
