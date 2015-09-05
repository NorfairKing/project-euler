import           Primes (primeFactorisation)

main :: IO ()
main = readLn >>= print . solve

solve :: Integer -> Integer
solve = maximum . primeFactorisation
