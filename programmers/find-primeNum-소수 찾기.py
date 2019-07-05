# https://programmers.co.kr/learn/courses/30/lessons/42839

from itertools import permutations


def checkPrime(num):
    if num is 1:
        return False
    else:
        for r in range(2, num):
            if num % r is 0:
                return False
    return True


def solution(numbers):
    numbers = list(numbers)
    ans = []

    for i in range(0, len(numbers) + 1):
        for c in permutations(numbers, i):
            target = int("".join(c)) if "".join(c) else 0
            if target and target not in ans and checkPrime(target):
                ans.append(target)

    return len(ans)


print(solution('17'))
print(solution('011'))
