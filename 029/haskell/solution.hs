import           Data.List (nub)

main :: IO ()
main = readLn >>= print . solve

-- Explicitly calculate every one of the powers and count them
solve :: Int -> Int
solve p = (length . nub) [ a^b | a <- as p, b <- bs p]

-- Define the range for the a and b
as, bs :: Int -> [Integer]
as p = [2.. fromIntegral p]
bs p = [2.. fromIntegral p]
