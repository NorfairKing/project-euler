import           Data.List

main :: IO ()
main = readLn >>= print . solve

solve :: Integer -> Int
solve p = length . filter n $ allAssignedDays p
    where n = (== (last dayNames, 1))

years :: Integer -> [Integer]
years p = [100*(p-1) + 1 .. 100*p - 1]

-- Constant inputs
daysNormal, daysLeap, dayNames :: [Integer]
daysNormal = [31,28,31,30,31,30,31,31,30,31,30,31]
daysLeap   = [31,29,31,30,31,30,31,31,30,31,30,31]
dayNames   = [1..7]

-- Whether or not a year is a leap year
isLeap :: Integral a => a -> Bool
isLeap year = (mod year 4 == 0)
            && ((mod year 400 == 0)
               || not (mod year 100 == 0))

-- A list of all day numbers of a specific year
yearDays :: Integral a => a -> [Integer]
yearDays y = concat $ map (\n -> [1..n]) d
    where d = if isLeap y then daysLeap else daysNormal

-- All day numbers from the 20th century
allDays :: Integer -> [Integer]
allDays p = concat $ map yearDays $ years p

-- A list of all days from the 20th century with their day named
allAssignedDays :: Integer -> [(Integer, Integer)]
allAssignedDays p = zip (cycle dayNames) (allDays p)
