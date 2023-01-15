def solution(arr, divisor):
    a = sorted(list(filter(lambda x: x % divisor == 0, arr)))
    return [-1] if len(a) == 0 else a