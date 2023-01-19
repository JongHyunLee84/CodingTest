def solution(price, money, count):
    a = money - sum([price*i for i in range(1,count+1)])
    return 0 if money - sum([price*i for i in range(1,count+1)]) >= 0 else abs(a)