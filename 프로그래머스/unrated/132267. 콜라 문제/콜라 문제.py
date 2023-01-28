def solution(a, b, n):
    result = 0
    while n >= a :
        n -= a
        n += b
        # print("n: ", n)
        result += b
        # print("result: ", result)
    return result 