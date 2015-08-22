import           Data.List
import           Multiple

main :: IO ()
main = readLn >>= print . solve

solve :: Integer -> Integer
solve p = f 3 + f 5 - f 15
  where f q = sum [q,2*q..(p-1)]
