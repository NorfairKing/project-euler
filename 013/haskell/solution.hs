import Control.Monad (replicateM)

solve :: Int -> [Integer] -> Integer
solve d = read . take d . show . sum

main :: IO ()
main = do
    d <- readLn
    _ <- getLine
    n <- readLn
    ints <- replicateM n readLn
    print $ solve d ints
