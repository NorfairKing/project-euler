from series import sum_naturals

def multiples_under(p, n):
    pdn = p // n
    if p % n == 0: pdn -= 1
    return n * sum_naturals(pdn)
