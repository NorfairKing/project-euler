main :: IO ()
main = readLn >>= print . solve

solve :: Integer -> Integer
solve p = sum [ n | n <- [1..p], isPalindromeNr n, isPalindromeBin (toBinary n) ]

-- Test whether a given number is palindromic
isPalindromeNr :: Integer -> Bool
isPalindromeNr n | n `mod` 10 == 0 = False
isPalindromeNr n | otherwise = l == reverse l
    where l = show n

-- Test wether a given list of binary digits represents a binary palindrome
isPalindromeBin :: [Integer] -> Bool
isPalindromeBin n | head n == 0 = False
isPalindromeBin n | otherwise = n == reverse n

-- Convert a decimal number to a list of binary digits.
toBinary :: Integer -> [Integer]
toBinary 0 = [0]
toBinary n = reverse (helper n)
    where
        helper 0 = []
        helper x = let (q,r) = x `divMod` 2 in r : helper q
