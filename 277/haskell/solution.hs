import           Data.List  (find, isPrefixOf)
import           Data.Maybe (fromJust)

main :: IO ()
main = do
  p <- read `fmap` getLine
  pat <- map fromChar `fmap` getLine
  print $ solve p pat

data Step = LargeDown | Up | SmallDown
  deriving Eq
type Pattern = [Step]

instance Show Step where
  show LargeDown = "D"
  show Up = "U"
  show SmallDown = "d"

fromChar :: Char -> Step
fromChar 'D' = LargeDown
fromChar 'U' = Up
fromChar 'd' = SmallDown
fromChar _   = error "unrecognised char"

solve :: Integer -> Pattern -> Integer
solve p pat = fst . fromJust . find (isPrefixOf pat . snd) . map (\n -> (n, collatz' n)) $ [min..]
  where min = 10 ^ p

collatz' :: Integer -> [Step]
collatz' 1 = []
collatz' n = case n `rem` 3 of
              0 -> LargeDown:(collatz' $ n `div` 3)
              1 -> Up:(collatz' $ (4 * n + 2) `div` 3)
              2 -> SmallDown:(collatz' $ (2 * n - 1) `div` 3)


