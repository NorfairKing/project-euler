import           Data.List

-- We want permutations of 0,1,2,3,4,5,6,7,8,9. These are 10 numbers, so p = 10.
p :: Integer
p = 10

-- We want the milionth permutation, so n = 10^6
n :: Int
n = 10^6

-- A list of all lexicographical permutations
lexPerm :: [[Integer]]
lexPerm = (sort . permutations) [0..(p-1)]

-- Take the nth lexographical permutation
solve :: String
solve = (stringify . head . (drop (n-1))) lexPerm

-- Make a lexicographical permutation readable
stringify :: [Integer] -> String
stringify = concat . (map show)

main :: IO ()
main = putStrLn solve
