def convert(n, q):
    rev_base = ''

    while n > 0:
        n, mod = divmod(n, q)
        rev_base += str(mod)

    return rev_base[::-1] 

def solution(n):
    a = convert(n,3)
    return int(''.join(reversed(a)), 3)
    