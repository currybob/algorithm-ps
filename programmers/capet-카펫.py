# https://programmers.co.kr/learn/courses/30/lessons/42842


def solution(brown, red):
    for i in range(1, int(red**0.5)+1):
        if not red % i:
            j = red // i
            if (i * 2 + j * 2 + 4) == brown:
                return [j+2, i+2]


print(solution(10, 2))
print(solution(8, 1))
print(solution(24, 24))
