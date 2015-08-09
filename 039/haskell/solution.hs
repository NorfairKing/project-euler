{- Compute all possibilities for two sides and check if the third one is possible. -}
allTriangles :: Integral t => t -> [(t, t, t)]
allTriangles n = [ (a,b,n-a-b) | a <- [1..n'], b <- [a..n'], a^2+b^2 == (n-a-b)^2  ]
    where n' = n `quot` 2

solve :: Integer -> Integer
solve p = (snd . maximum) [ (length $ allTriangles n, n) | n <- [1..p]]

main :: IO ()
main = print $ solve 1000
