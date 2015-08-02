import           Control.Monad

p :: Int
p = 5

-- Split an integer into its digits
digits :: Integral x => x -> [x]
digits 0 = []
digits x = digits (x `div` 10) ++ [x `mod` 10]

-- Generate the list of all possible sets of q adjacent elements from a list
setsOf :: Int -> [a] -> [[a]]
setsOf q l | length l < q = [[]]
setsOf q list = (take q list):(setsOf q $ tail list)

solve :: Integer -> Integer
solve nr = (maximum . (map product) . (setsOf p) . digits) nr

-- IO
rd :: String -> Integer
rd x = read x :: Integer

main :: IO ()
main = do
    ds <- replicateM 20 getLine
    putStrLn $ (show . solve . rd . concat) ds
