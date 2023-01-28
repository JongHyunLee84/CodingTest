
def solution(t, p):
    return len(list(filter(lambda x: x <= p, [t[i:i+len(p)] for i in range(len(t) - len(p)+1)])))
    
    