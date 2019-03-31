// https://programmers.co.kr/learn/courses/30/lessons/42587?language=javascript

// O(N^2)
function solution(priors, location) {
  let cnt = 0;
  const queue = priors.map((prior, idx) => ({
    prior,
    isTarget: location === idx,
  }));

  while (true) {
    let { prior, isTarget } = queue.shift();
    let hasMore = queue.some(item => item.prior > prior);

    if (hasMore) {
      queue.push({ prior, isTarget });
    } else {
      cnt++;

      if (isTarget) return cnt;
    }
  }
}

// O(N)
function solution(priors, location) {
  let queue = [...priors];
  let cnt = 0;

  while (true) {
    let max = Math.max(...queue);

    if (queue[0] !== max) {
      queue.push(queue.shift());
      (location && location--) || (location = queue.length - 1);
    } else {
      queue.shift();
      cnt++;
      if (location === 0) return cnt;
      (location && location--) || (location = queue.length - 1);
    }
  }
}

console.time();
console.log(solution([2, 1, 3, 2], 2));
console.log(solution([1, 1, 9, 1, 1, 1], 0));
console.timeEnd();
