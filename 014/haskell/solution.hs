import Data.List (maximumBy, comparing)

main :: IO ()
main = readLn >>= print . solve

collatzLength :: Int -> Int
collatzLength 1 = 1
collatzLength n = 1 + collatzLength (collatzNext n)

collatzNext :: Int -> Int
collatzNext n
    | even n = n `div` 2
    | otherwise = 3 * n + 1

solve :: Int -> Int
solve p = fst $ maximumBy (comparing snd) $ map (\i -> (i, collatzLength i) [1..p]
