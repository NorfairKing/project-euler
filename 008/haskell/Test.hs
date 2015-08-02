{-# LANGUAGE CPP #-}
{-# OPTIONS_GHC -F -pgmF htfpp #-}
module Test where

import           Test.Framework

#include "solution.hs"

test_easy = assertEqual (solve 4) 5832
test_correct = assertEqual (solve 13) 23514624000

test = htfMain htf_thisModulesTests

