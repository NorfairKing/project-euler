import Data.List

p :: Int
p = 4000000

fibs :: [Int]
fibs = 0 : 1 : zipWith (+) fibs (tail fibs)

evenFibs :: [Int]
evenFibs = [ x | x <- fibs, x `rem` 2 == 0]

solve :: Int
solve = sum $ takeWhile (<= p) evenFibs

-- IO
main :: IO ()
main = do
    putStrLn $ show solve        
