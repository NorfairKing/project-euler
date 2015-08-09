import Data.Char
import Data.List
import Data.Maybe

alphabet :: [Char]
alphabet = "#ABCDEFGHIJKLMNOPQRSTUVWXYZ"

findI :: Eq a => [a] -> a -> Int
findI list e = fromJust $ elemIndex e list

value :: String -> Int
value str = sum $ map rank str -- sum $ map (findI alphabet) str
    where rank = findI alphabet 

solve :: [String] -> Int
solve names = sum $ zipWith (*) values [1..]
    where values = map value names

-- IO
main :: IO ()
main = do
    line <- getLine
    let names = sort $ read $ "["++ line ++"]" 
    putStrLn $ (show . solve) names 
