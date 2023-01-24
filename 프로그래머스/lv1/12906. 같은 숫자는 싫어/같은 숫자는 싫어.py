

def solution(arr):
    a= 10
    b= []
    for i in arr:
        if i != a :
            b.append(i)
            a= i
        else: 
            a= i
    return b