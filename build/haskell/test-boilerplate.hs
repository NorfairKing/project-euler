{-# LANGUAGE CPP #-}
{-# OPTIONS_GHC -F -pgmF htfpp #-}
module TestTmp where
import           Test.Framework
#include "solution.hs"
test = htfMain htf_thisModulesTests

