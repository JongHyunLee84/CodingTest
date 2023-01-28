
def solution(t, p):
    a = [i for i in range(len(t))]
    
    b = [a[i:i+len(p)] for i in range(len(t)-len(p)+1)]
    
    c = []
    
    result = 0
    for i in b:
        d = ""
        for j in i:
            d += t[j]
        c.append(d)
    
    for i in c:
        if i <= p:
            result += 1
            
    return result
    
    
    