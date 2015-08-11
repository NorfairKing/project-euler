main = print $ solve 20

solve :: Int -> Integer
solve p = go p p

go :: Int -> Int -> Integer
go 0 0 = 1
go x 0 = 1
go 0 y = 1
go x y = go (x-1) y + go x (y-1)
