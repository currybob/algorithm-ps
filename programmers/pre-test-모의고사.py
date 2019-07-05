# https://programmers.co.kr/learn/courses/30/lessons/42840


def solution(answers):
    ansLen = len(answers)

    one = [1, 2, 3, 4, 5] * (int(ansLen / 5) + 1)
    two = [2, 1, 2, 3, 2, 4, 2, 5] * (int(ansLen / 8) + 1)
    three = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5] * (int(ansLen / 10) + 1)

    one = one[:ansLen]
    two = two[:ansLen]
    three = three[:ansLen]

    score = [0, 0, 0]

    for idx, ans in enumerate(answers):
        if one[idx] == ans:
            score[0] += 1
        if two[idx] == ans:
            score[1] += 1
        if three[idx] == ans:
            score[2] += 1

    maxScore = max(score)
    ans = []

    for idx, scr in enumerate(score):
        if scr == maxScore:
            ans.append(idx + 1)

    ans.sort()

    return ans


print(solution([1, 2, 3, 4, 5]))
print(solution([1, 3, 2, 4, 2]))
print(solution([1, 3, 2, 4, 2, 1, 3, 2, 4, 2, 1, 3, 2, 4, 2, 1,
                3, 2, 4, 2, 1, 3, 2, 4, 2, 1, 3, 2, 4, 2, 1, 3, 2, 4, 2]))
