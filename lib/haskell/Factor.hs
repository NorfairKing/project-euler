module Factor where

-- Returns whether n is a factor of p
-- Time: O(1), Space: O(1)
isFactorOf :: Integer -> Integer -> Bool
isFactorOf n p = p `rem` n == 0
