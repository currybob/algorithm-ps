# https://programmers.co.kr/learn/courses/30/lessons/42626

import heapq


def solution(scoville, K):
    cnt = 0
    heapq.heapify(scoville)

    while True:
        if (all(i >= K for i in scoville)):
            break
        try:
            a = heapq.heappop(scoville)
            b = heapq.heappop(scoville)
            target = (a + (b * 2))

            heapq.heappush(scoville, target)
            cnt += 1
        except:
            return -1

    return cnt


print(solution([1, 2, 3, 9, 10, 12], 7))
print(solution([1, 2, 3, 9, 10, 12, 13, 41,
                2, 3, 123, 3232, 123, 4, 4, 2, 31], 7))
