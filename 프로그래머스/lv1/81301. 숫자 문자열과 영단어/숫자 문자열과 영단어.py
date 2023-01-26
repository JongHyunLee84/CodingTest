def solution(s):
    a = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
    array = list(s)
    while not s.isdigit():
        for i in a:
            if i in s:
                b = s.index(i)
                array[b] = str(a.index(i))
                del array[b+1:b+len(i)]
                s = "".join(array)
    return int(s)