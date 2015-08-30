module Power where

powers :: Integer -> [Integer]
powers n = map (^n) [1..]
