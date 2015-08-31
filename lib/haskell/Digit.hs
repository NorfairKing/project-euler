module Digit where

digits :: Integer -> [Integer]
digits x | x < 10 = [x]
digits x = (digits $ x `div` 10) ++ [(x `rem` 10)]

nrDigits :: Integer -> Integer
nrDigits x | x < 10 = 1
nrDigits x = 1 + (nrDigits $ x `div` 10)

fromDigits :: [Integer] -> Integer
fromDigits = go 0
  where
    go :: Integer -> [Integer] -> Integer
    go acc [] =  acc
    go acc (d:ds) = go (10 * acc + d) ds
