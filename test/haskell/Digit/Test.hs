{-# OPTIONS_GHC -F -pgmF htfpp #-}
module Digit.Test (htf_thisModulesTests) where

import           Data.List
import           Digit
import           Test.Framework

test_nrDigits = assertEqual (nrDigits 5)  1

prop_digits_nrDigits :: Integer -> Bool
prop_digits_nrDigits x = (nrDigits x) == (genericLength $ digits x)
