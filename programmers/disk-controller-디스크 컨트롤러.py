# https://programmers.co.kr/learn/courses/30/lessons/42627

import heapq
import math


def solution(jobs):
    now = 0
    total = 0
    size = len(jobs)
    jobs.sort()

    while jobs:
        queue = []

        for idx, job in enumerate(jobs):
            if job[0] > now:
                break
            heapq.heappush(queue, (job[1], idx))
            # 현재 가능한 작업 집어넣기
            # 우선순위는 정렬된 인덱스

        if queue:
            exe = jobs.pop(queue[0][1])  # 실행될 작업
            now += exe[1]
            total += now-exe[0]
        else:
            now += 1

    return math.trunc(total / size)


print(solution([[0, 3], [1, 9], [2, 6], [44, 5]]	))
