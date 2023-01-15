def solution(seoul):
    for x,y in enumerate(seoul):
        if y == "Kim":
            return f'김서방은 {x}에 있다'