module Multiple where

import           Factor

-- Returns all multiples of n under p
-- Time: O(1), Space: O(1)
multiples_under :: Integer -> Integer -> Integer
multiples_under p n = (n * pdn * (pdn + 1)) `div` 2
  where pdn = p `div` n - if n `isFactorOf` p then 1 else 0
