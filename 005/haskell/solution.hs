import           Data.List (foldl')
main = print $ solve 20

solve :: Integer -> Integer
solve p = lcml [2..p]

lcml :: Integral a => [a] -> a
lcml = foldl' lcm 1
