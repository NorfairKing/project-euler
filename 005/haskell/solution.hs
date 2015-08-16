import           Data.List (foldl')

main = readLn >>= print . solve

solve :: Integer -> Integer
solve p = lcml [2..p]

lcml :: Integral a => [a] -> a
lcml = foldl' lcm 1
