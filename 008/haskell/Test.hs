{-# LANGUAGE CPP #-}
{-# OPTIONS_GHC -F -pgmF htfpp #-}
module Test where

import           Test.Framework
#include "solution.hs"

test_correct = assertEqual True True

test = htfMain htf_thisModulesTests

