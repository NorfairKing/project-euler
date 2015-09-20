import           Data.Char (chr, ord)
import           Data.List (genericLength)
import           Triangle  (isTriangle)

main :: IO ()
main = do
  line <- getLine
  let ws = read $ "[" ++ line ++ "]"
  print $ solve ws

solve :: [String] -> Integer
solve = genericLength . filter isTriangle . map wordValue

wordValue :: String -> Integer
wordValue = sum . map (fromIntegral . (\c -> c - offset) . ord)
  where offset = (ord 'A') - 1
