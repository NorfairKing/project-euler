import           Control.Monad
import           Data.List

p = 4

factorList :: [a] -> [[a]]
factorList [] = []
factorList list | length list < p = []
factorList list = [(take p list)] ++ (factorList $ tail list)

diagonals :: [[a]] -> [[a]]
diagonals [] = []
diagonals m = concatMap factorList lists
        where
            lists = (lasts (f lowerLeft)) ++
                    (lasts (f lowerRight)) ++
                    (heads (f upperLeft)) ++
                    (heads (f upperRight))
            lowerLeft = zipWith take [0..] m
            upperRight = zipWith drop [0..] m
            lowerRight = zipWith take ll m
            upperLeft = zipWith drop ll m
            ll = [(n-1),(n-2)..0]
            n = length m

heads :: [[a]] -> [[a]]
heads [] = []
heads list = [(map head list)] ++ (heads (f (map tail list)))

lasts :: [[a]] -> [[a]]
lasts [] = []
lasts list = [(map last list)] ++ (lasts (f (map init list)))

f :: [[a]] -> [[a]]
f = filter (not . null)

verticals :: [[a]] -> [[a]]
verticals = (horizontals . transpose)

horizontals :: [[a]] -> [[a]]
horizontals =  concatMap factorList

solve :: [[Int]] -> Int
solve matrix = maximum $ map product factors
        where
            factors = d ++ v ++ h
            d = diagonals matrix
            v = verticals matrix
            h = horizontals matrix

-- IO
rd :: String -> Int
rd x  = read x :: Int

getInt :: IO Int
getInt = read `liftM` getLine :: IO Int

getInts :: IO [Int]
getInts = do
        line <- getLine
        return (map rd $ words line)

main :: IO ()
main = do
    n <- getInt
    matrix <- replicateM n getInts
    putStrLn $ show (solve matrix)
