def solution(n):
    return int("".join(map(str,sorted(list(str(n)), reverse=True))))
            # int("".join(sorted(list(str(n)), reverse=True)))