data Frac = F (Frac) (Frac)
          | A (Frac) (Frac)
          | N Integer
    deriving (Show, Eq)

data FullFrac = Fr Integer Integer
    deriving (Show, Eq)

expan :: Integer -> Frac
expan 1 = A (N 1) (F (N 1) (N 2))
expan n = A (N 1) (F (N 1) (inf n))
    where
        inf 1 = N 2
        inf n =  (A (N 2) (F (N 1) (inf (n-1))))

evalFrac :: Frac -> FullFrac
evalFrac (N n) = Fr n 1
evalFrac (A f g) = Fr (a*d+b*c) (b*d)
    where
        Fr a b = evalFrac f
        Fr c d = evalFrac g
evalFrac (F f g) = Fr (a*d) (b*c)
    where
        Fr a b = evalFrac f
        Fr c d = evalFrac g

nDigits :: Integer -> Int
nDigits 0 = 0
nDigits x = 1 + (nDigits (div x 10))

solve :: Integer -> Int
solve p = length $ filter largerNumerator $ map (evalFrac . expan) [1..p]
    where largerNumerator = (\(Fr n d) -> (nDigits n) > (nDigits d))

main :: IO ()
main = print $ solve 1000
