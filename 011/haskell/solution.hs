import           Control.Monad
import           Data.List

factorList :: Int -> [a] -> [[a]]
factorList _ [] = []
factorList p list | length list < p = []
factorList p list = [(take p list)] ++ (factorList p $ tail list)

diagonals :: Int -> [[a]] -> [[a]]
diagonals _ [] = []
diagonals p m = concatMap (factorList p) lists
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

verticals :: Int -> [[a]] -> [[a]]
verticals p = (horizontals p . transpose)

horizontals :: Int -> [[a]] -> [[a]]
horizontals p = concatMap (factorList p)

solve :: [[Int]] -> Int -> Int
solve matrix p = maximum $ map product factors
        where
            factors = d ++ v ++ h
            d = diagonals p matrix
            v = verticals p matrix
            h = horizontals p matrix

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
    p <- getInt
    n <- getInt
    matrix <- replicateM n getInts
    putStrLn $ show (solve matrix p)
