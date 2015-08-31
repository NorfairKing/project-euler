module Pandigital where

import           Data.List (sort)
import           Digit     (digits)

pandigital :: Integer -> Integer -> Bool
p `pandigital` n = [1..p] == (sort $ digits n)
