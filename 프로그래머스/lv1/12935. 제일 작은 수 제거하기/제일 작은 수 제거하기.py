def solution(arr):
    a = min(arr)
    return list(filter(lambda x: x != a, arr)) if len(arr) > 1 else [-1]