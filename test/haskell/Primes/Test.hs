{-# OPTIONS_GHC -F -pgmF htfpp #-}
module Primes.Test (htf_thisModulesTests) where

import           Data.List
import           Primes
import           Test.Framework

test_primeFactorisation_5  = assertEqual (primeFactorisation 5)  [5]
test_primeFactorisation_55 = assertEqual (primeFactorisation 55) [5,11]
test_primeFactorisation_24 = assertEqual (primeFactorisation 24) [2,2,2,3]

