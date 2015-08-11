import           Data.List (maximumBy)

itseq :: Int -> [Int]
itseq 1 = [1]
itseq n | even n    = n: itseq (n `div` 2)
        | otherwise = n: itseq (3 * n + 1)

l = fst $ maximumBy (\x y -> compare (snd x) (snd y)) $ zip [1..1000000] $ map (length . itseq) [1..1000000]

main = print l
-- Idea: build a graph? backwards
