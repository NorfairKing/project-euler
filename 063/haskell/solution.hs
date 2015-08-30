import           Data.List
import           Digit     (nrDigits)
import           Power     (powers)

main :: IO ()
main = print solve

solve :: Integer
solve = genericLength . concat . takeWhile (not . null) $ map nDigitPowers [1..]

nDigitPowers :: Integer -> [Integer]
nDigitPowers n = takeWhile (\x -> nrDigits x == n) . dropWhile (\x -> nrDigits x < n) $ powers n
