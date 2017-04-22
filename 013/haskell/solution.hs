import Control.Monad (replicateM)

solve :: [Integer] -> Integer
solve = read . take 10 . show . sum

main :: IO ()
main = do
    _ <- getLine
    _ <- getLine
    n <- readLn
    ints <- replicateM n readLn
    print $ solve ints
