main :: IO ()
main = readLn >>= print . solve

solve :: Int -> Integer
solve p = maximum [ x*y | x <- pDigitNumbers p, y <- pDigitNumbers p, isPalindrome (x*y) ]

pDigitNumbers :: Int -> [Integer]
pDigitNumbers p = [10^(p-1) .. 10^p]

isPalindrome :: Show a => a -> Bool
isPalindrome ll = l == reverse l
    where l = show ll
