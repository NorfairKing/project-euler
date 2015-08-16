import           Primes

main :: IO ()
main = readLn >>= print . solve

solve :: Int -> Integer
solve p = primes !! (p-1)
