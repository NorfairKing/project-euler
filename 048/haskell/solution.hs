import           Text.Printf (printf)

-- Explicitly calculate the sum and get the last p digits by performing a modulo operation.
solve :: Integer -> Integer -> String
solve p n = printf ("%0" ++ show p ++ "d") $ (sum [ a^a | a <- [1..n]]) `mod` 10^p

main :: IO ()
main = putStrLn $ solve 10 1000
