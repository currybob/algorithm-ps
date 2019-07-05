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
