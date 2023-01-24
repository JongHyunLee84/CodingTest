def solution(sizes):
    a= 0
    b= 0
    for i in sizes:
        s = sorted(i)
        if s[0] > a:
            a = s[0]
        if s[1] > b:
            b = s[1]
    return a*b 