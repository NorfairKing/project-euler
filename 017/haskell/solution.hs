import           Data.List

main :: IO ()
main = readLn >>= print . solve

solve :: Int -> Int
solve p = sum $ map (length . stringify) [1..p]

smalls :: [String]
smalls = [ "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" ]

tens :: [String]
tens = [ "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", "hundred" ]

-- Convert a small integer to its name.
-- This method nicely shows how language is overly complex when it comes to numbers.
stringify :: Int -> String
stringify n | n < 20 = smalls !! n
stringify n | n >= 20 && n < 100 = (tens !! (firstDigit - 2)) ++ stringify secondDigit
    where
        firstDigit = n `div` 10
        secondDigit = n `rem` 10
stringify n | n >= 100 && n < 1000 = smalls !! firstDigit ++ "hundred" ++ sndPart
    where
        sndPart = if rest == 0 then "" else "and" ++ stringify rest
        firstDigit = n `div` 100
        rest = n `rem` 100
stringify 1000 = "onethousand"
stringify _ = undefined
