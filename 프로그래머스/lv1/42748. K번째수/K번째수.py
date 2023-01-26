def solution(array, commands):
    result = []
    for a,b,c in commands:
        d = sorted(array[a-1:b])[c-1]
        result.append(d)
    return result
        