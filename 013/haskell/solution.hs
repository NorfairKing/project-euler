import           Control.Monad (replicateM)

solve :: [Integer] -> Integer
solve = read . take 10 . show . sum

main :: IO ()
main = do
    ints <- replicateM 100 readLn
    print $ solve ints
