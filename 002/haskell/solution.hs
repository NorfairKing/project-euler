import           Data.List
import           Fibonacci

solve :: Integer -> Integer
solve p = sum $ takeWhile (<= p) $ filter even fibs

main :: IO ()
main = print $ solve 4000000
