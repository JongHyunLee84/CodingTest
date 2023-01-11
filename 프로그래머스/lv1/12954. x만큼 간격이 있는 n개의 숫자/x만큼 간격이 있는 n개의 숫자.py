def solution(x, n):
    num = 0
    array = []
    for _ in range(n):
        num += x
        array.append(num)
    return array