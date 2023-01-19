def solution(s):
    a = s.split(" ")
    c = []
    for i in a:
        b = []
        for j in range(len(i)):
            if j == 0 or j % 2 == 0:
                b.append(i[j].upper())
            else:
                b.append(i[j].lower())
        c.append("".join(b))
    return " ".join(c)    
        
                
                