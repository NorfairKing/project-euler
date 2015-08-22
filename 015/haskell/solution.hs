import           Data.Function.Memoize (memoize2)

main :: IO ()
main = readLn >>= print . solve

solve :: Int -> Integer
solve p = fast_go p p

fast_go :: Int -> Int -> Integer
fast_go = memoize2 go

go :: Int -> Int -> Integer
go 0 0 = 1
go x 0 = 1
go 0 y = 1
go x y = fast_go (x-1) y + fast_go x (y-1)
