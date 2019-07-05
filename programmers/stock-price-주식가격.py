# * https://programmers.co.kr/learn/courses/30/lessons/42584


def solution(prices):
    answer = [0] * len(prices)
    for i in range(len(prices)):
        for j in range(i + 1, len(prices)):
            if prices[i] > prices[j]:
                answer[i] = j - i
                break
            if j == len(answer) - 1:
                answer[i] = j - i
    return answer


print(solution([1, 2, 3, 2, 3]))
print(solution([498, 501, 470, 489]))
