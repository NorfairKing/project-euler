import           Data.List
import           Fibonacci

main :: IO ()
main = readLn >>= print . solve

-- [002/explanation.tex]
solve :: Integer -> Integer
solve p = sum $ takeWhile (<= p) $ filter even fibs
