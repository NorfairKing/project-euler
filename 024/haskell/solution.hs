import           Data.List

main :: IO ()
main = do
  p <- readLn
  n <- readLn
  putStrLn $ solve p n

-- Take the nth lexographical permutation
solve :: Integer -> Int -> String
solve p n = stringify . head . (drop (n-1)) $ lexPerm p

-- A list of all lexicographical permutations
lexPerm :: Integer -> [[Integer]]
lexPerm p = (sort . permutations) [0..(p-1)]

-- Make a lexicographical permutation readable
stringify :: [Integer] -> String
stringify = concat . (map show)
