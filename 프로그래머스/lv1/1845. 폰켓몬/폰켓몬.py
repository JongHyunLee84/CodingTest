from itertools import combinations

def solution(nums):
    a = []

    for i in nums:
        if i not in a:
            a.append(i)

    b = len(nums)    
    c = len(a)
    return c if c <= b // 2 else b // 2