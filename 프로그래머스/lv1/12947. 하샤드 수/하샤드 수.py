def solution(x):
    a = [i for i in str(x)]
    return True if x % sum([int(i) for i in a]) == 0 else False