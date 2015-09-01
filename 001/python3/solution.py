from sys import stdin
from multiple import multiples_under

def solve(p):
    return multiples_under(p,3) + multiples_under(p,5) - multiples_under(p,15)

p = int(stdin.readline())
print(int(solve(p)))
