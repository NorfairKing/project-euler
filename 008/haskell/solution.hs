main :: IO ()
main = do
  p <- readLn
  _ <- getLine
  number <- readLn
  print $ solve p number

solve :: Int -> Integer -> Integer
solve p number = (maximum . (map product) . (setsOf p) . digits) number

-- Split an integer into its digits
digits :: Integral x => x -> [x]
digits 0 = []
digits x = digits (x `div` 10) ++ [x `mod` 10]

-- Generate the list of all possible sets of q adjacent elements from a list
setsOf :: Int -> [a] -> [[a]]
setsOf q l | length l < q = [[]]
setsOf q list = (take q list):(setsOf q $ tail list)
