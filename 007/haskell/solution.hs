import           Primes

solve :: Int -> Integer
solve p = primes !! (p-1)

main :: IO ()
main = print $ solve 10001
