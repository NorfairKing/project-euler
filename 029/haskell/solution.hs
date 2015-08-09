import           Data.List

-- Define the range for the a and b
as, bs :: Int -> [Integer]
as p = [2.. fromIntegral p]
bs p = [2.. fromIntegral p]

-- Explicitly calculate every one of the powers and count them
solve :: Int -> Int
solve p = (length . nub) [ a^b | a <- as p, b <- bs p]

main :: IO ()
main = print $ solve 100
