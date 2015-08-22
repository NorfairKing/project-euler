import           Data.List (maximumBy)

main :: IO ()
main = readLn >>= print . solve

itseq :: Int -> [Int]
itseq 1 = [1]
itseq n | even n    = n: itseq (n `div` 2)
        | otherwise = n: itseq (3 * n + 1)

solve :: Int -> Int
solve p = fst $ maximumBy snds $ zip int $ map (length . itseq) int
  where
    snds = (\x y -> compare (snd x) (snd y))
    int = [1..p]
