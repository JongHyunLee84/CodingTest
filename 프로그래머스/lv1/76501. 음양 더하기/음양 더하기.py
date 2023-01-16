def solution(absolutes, signs):
    a = []
    for i in range(len(absolutes)):
        if signs[i] :
            a.append(absolutes[i])
        else :
            a.append(absolutes[i] * -1)
    return sum(a)