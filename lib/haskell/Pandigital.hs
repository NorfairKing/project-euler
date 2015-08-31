module Pandigital where

import           Data.List (sort)
import           Digit     (digits)

pandigital :: Integer -> Integer -> Bool
p `pandigital` n = digits n == sort [1..p]
