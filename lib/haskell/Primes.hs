module Primes where

primes :: [Integer]
primes = sieve [2..]
  where sieve (p:xs) = p : sieve [ x | x <- xs, x `rem` p /= 0]

