def solution(strings, n):
    a = sorted(strings)
    for _ in range(len(a)-1):
        for i in range(len(a)-1):
            if a[i][n] > a[i+1][n]:
                a[i], a[i+1] = a[i+1], a[i]
    return a