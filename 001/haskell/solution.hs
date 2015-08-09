import           Data.List

main :: IO ()
main = print $ solve 1000

solve :: Int -> Int
solve p = sum $ [3, 6 .. (p-1)] ++ [5, 10 .. (p-1)] ++ [-15, -30 .. -(p-1)]
