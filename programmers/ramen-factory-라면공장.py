# https://programmers.co.kr/learn/courses/30/lessons/42629
import heapq


def solution(stock, dates, supplies, k):
    cnt = 0
    idx = 0
    heap = []
    heapq._heapify_max(heap)

    while(stock < k):
        for i in range(idx, len(dates)):
            if dates[i] > stock:
                break

            heapq.heappush(heap, (-supplies[i], supplies[i]))
            idx = i+1

        stock += heapq.heappop(heap)[1]
        cnt += 1
    return cnt


print(solution(4, [4, 10, 15], [20, 5, 10],	30))
