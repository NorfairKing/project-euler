module Digit where

digits :: Integer -> [Integer]
digits x | x < 10 = [x]
digits x = (x `rem` 10):(digits $ x `div` 10)

nrDigits :: Integer -> Integer
nrDigits x | x < 10 = 1
nrDigits x = 1 + (nrDigits $ x `div` 10)

fromDigits :: [Integer] -> Integer
fromDigits = go 1 . reverse
  where
    go :: Integer -> [Integer] -> Integer
    go _ [] =  0
    go b (d:ds) = b * d + go (10*b) ds
