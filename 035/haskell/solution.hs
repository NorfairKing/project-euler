import           Data.List

-- The integer nearest to the square root of a number
integerRoot :: Int -> Int
integerRoot = floor . sqrt . fromIntegral

-- All primes until a number
primesUntil :: Int -> [Int]
primesUntil n = sieve [2..n]
  where
    sieve [] = []
    sieve (p:xs) | p >= n' = p:xs
    sieve (p:xs) = p : sieve [x|x <- xs, x `rem` p /= 0]
    n' = integerRoot n

-- Test whether a number is prime
prime :: Int -> Bool
prime 2 = True
prime k =  null [ x | x <- [2..k'], k `mod`x  == 0]
  where
    k' = integerRoot k

-- n must be prime!
isCircular :: Show a => a -> Bool
isCircular n = all prime $ nrRots n

-- Rotations of a number
nrRots :: Show a => a -> [Int]
nrRots n = map read (rots $ show n) :: [Int]
    where rots xs = init (zipWith (++) (tails xs) (inits xs))

solve :: Int -> Int
solve p = (length . (filter isCircular) . primesUntil) p

main :: IO ()
main = print $ solve 1000000
