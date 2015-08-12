import           Data.List (takeWhile)
import           Fibonacci

main = print $ solve 1000

nrDigits :: Integer -> Int
nrDigits = fromIntegral . length . show

solve :: Int -> Int
solve p = length $ takeWhile ((<p) . nrDigits) fibs
