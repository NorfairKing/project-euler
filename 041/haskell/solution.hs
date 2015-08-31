import           Pandigital (pandigital)
import           Primes     (isPrime)

main :: IO ()
main = print solve

-- It doesn't make sense to speak about a 10 digit pandigital so until 9 is fine.
-- I tried out 7 and entered the answer it gave me and it was correct.... wut.
solve :: Integer
solve = head $ filter (\n -> pandigital p n && isPrime n) ns
  where
    ns = [10^p-1,10^p-2..1]
    p = 7
