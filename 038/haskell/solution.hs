import           Data.List  (genericLength)
import           Data.Maybe (catMaybes)
import           Digit      (digits, fromDigits)
import           Pandigital (pandigital)

main :: IO ()
main = readLn >>= print . solve

solve :: Integer -> Integer
solve p = maximum $ filter (pandigital p) $ catMaybes $ map (digitConcatenatedProducts p) [1..10^((p `div` 2) + 1)]

digitConcatenatedProducts :: Integer -> Integer -> Maybe Integer
p `digitConcatenatedProducts` n = go (digits n) [2..]
  where
    go :: [Integer] -> [Integer] -> Maybe Integer
    go _ [] = error "this won't happen because we're supplying an infinite list"
    go ds _ | genericLength ds == p = Just $ fromDigits ds
            | genericLength ds >  p = Nothing
    go ds (b:bs) = go (ds ++ digits (b * n)) bs
