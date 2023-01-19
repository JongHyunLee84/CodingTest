import math

def solution(n, m):
    a = math.gcd(n,m)
    return [a, n*m // a ]