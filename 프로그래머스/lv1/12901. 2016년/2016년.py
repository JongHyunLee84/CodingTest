def solution(a, b):
    month = {0:31, 1:29, 2:31, 3:30, 4:31, 5:30, 6:31, 7:31, 8:30, 9:31, 10:30, 11:31}
    day = ['FRI', 'SAT', 'SUN', 'MON', 'TUE', 'WED', 'THU']
    
    days = 0
    
    for i in range(a-1):
        days += month.get(i)
        
    days += b
    
    return day[days % 7 - 1]