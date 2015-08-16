import           Data.List
import           Fibonacci

main :: IO ()
main = readLn >>= print . solve

solve :: Integer -> Integer
solve p = sum $ takeWhile (<= p) $ filter even fibs
