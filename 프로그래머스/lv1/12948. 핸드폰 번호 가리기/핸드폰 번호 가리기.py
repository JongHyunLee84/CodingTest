def solution(phone_number):
    a = ''
    for i in range(len(phone_number)):
        if i < len(phone_number) - 4:
            a += '*'
        else :
            a += phone_number[i]
    return a     
    