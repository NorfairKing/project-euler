module Triangle where

triangles :: [Integer]
triangles = map (\n -> (n * (n + 1)) `div` 2) [1..]

isTriangle :: Integer -> Bool
isTriangle num = num `elem` (takeWhile (<= num) triangles)
