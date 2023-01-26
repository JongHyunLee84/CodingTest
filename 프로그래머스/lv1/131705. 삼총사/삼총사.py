from itertools import combinations

def solution(number):
    return len(list(filter(lambda x: sum(x) == 0,list(combinations(number, 3)))))