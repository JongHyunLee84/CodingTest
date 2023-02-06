from collections import deque

def solution(numbers, target):
    deq = deque()
    deq2 = deque()
    deq.append(numbers[0])
    deq.append(-numbers[0])
    for i in range(1,len(numbers)):
        while deq:
            a = deq.popleft()
            deq2.append(a+numbers[i])
            deq2.append(a-numbers[i])
        while deq2:
            deq.append(deq2.popleft())
    
    return deq.count(target)
            