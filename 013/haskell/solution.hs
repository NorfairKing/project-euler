import           Control.Monad (replicateM)

solve :: [Integer] -> Integer
solve = read . take 10 . show . sum

main :: IO ()
main = do
    _ <- getLine
    ints <- replicateM 100 readLn
    print $ solve ints
