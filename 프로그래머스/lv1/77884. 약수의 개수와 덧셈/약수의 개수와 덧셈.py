def solution(left, right):
    return sum(list(map(lambda x: x if len([i for i in range(1,x+1) if x % i == 0]) % 2 == 0 else x * -1, range(left, right+1))))