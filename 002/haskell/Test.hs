{-# LANGUAGE CPP #-}
{-# OPTIONS_GHC -F -pgmF htfpp #-}
module Test where

import           Test.Framework

#include "solution.hs"

test_easy = assertEqual (solve 100) 44
test_correct = assertEqual (solve 4000000) 4613732

test = htfMain htf_thisModulesTests

