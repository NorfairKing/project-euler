import           Data.List

fibs :: [Int]
fibs = 0 : 1 : zipWith (+) fibs (tail fibs)

solve :: Int -> Int
solve p = sum $ takeWhile (<= p) $ filter even fibs

main :: IO ()
main = print $ solve 4000000
