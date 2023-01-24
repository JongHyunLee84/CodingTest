def solution(s, n):
    a = 'abcdefghijklmnopqrstuvwxyz'
    b = a.upper()
    result = ''
    for i in s:
        if i.isupper() :
            if b.index(i) + n <= 25:
                result += b[b.index(i)+n]
            else:
                result += b[(b.index(i)+n) - 26]
        elif i.islower() :
            if a.index(i) + n <= 25:
                result += a[a.index(i)+n]
            else:
                result += a[(a.index(i)+n) - 26]
        else:
            result += " "
    return result
        