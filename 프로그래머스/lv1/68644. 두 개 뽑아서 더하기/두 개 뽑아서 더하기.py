from itertools import combinations

def solution(numbers):
    
    return list(sorted(set([sum(i) for i in list(combinations(numbers, 2))])))