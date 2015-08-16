import           Data.Char
import           Data.List
import           Data.Maybe

main :: IO ()
main = do
    line <- getLine
    let names = sort $ read $ "["++ line ++"]"
    putStrLn $ (show . solve) names

solve :: [String] -> Int
solve names = sum $ zipWith (*) values [1..]
    where values = map value names

alphabet :: [Char]
alphabet = "#ABCDEFGHIJKLMNOPQRSTUVWXYZ"

findI :: Eq a => [a] -> a -> Int
findI list e = fromJust $ elemIndex e list

value :: String -> Int
value str = sum $ map rank str
    where rank = findI alphabet
