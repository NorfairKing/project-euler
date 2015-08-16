import           Data.List

main :: IO ()
main = readLn >>= print . solve

solve :: Int -> Int
solve p = sum $ [3, 6 .. (p-1)] ++ [5, 10 .. (p-1)] ++ [-15, -30 .. -(p-1)]
