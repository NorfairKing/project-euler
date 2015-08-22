import           Data.List (takeWhile)
import           Fibonacci

main :: IO ()
main = readLn >>= print . solve

nrDigits :: Integer -> Int
nrDigits = fromIntegral . length . show

solve :: Int -> Int
solve p = length $ takeWhile ((<p) . nrDigits) fibs
