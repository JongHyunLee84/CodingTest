def solution(n):
    return int("".join(map(str,sorted([int(i) for i in str(n)], reverse=True))))