def solution(d, budget):
    a = 0
    c = 0
    b = sorted(d)
    for i in b:
        if a > budget:
            return c -1
        elif a == budget:
            return c
        a += i
        c += 1
    return c -1 if a > budget else c
        