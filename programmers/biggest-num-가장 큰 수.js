// * https://programmers.co.kr/learn/courses/30/lessons/42746

function solution(numbers) {
  numbers = numbers.map(i => String(i));
  numbers.sort((a, b) => b + a - (a + b));

  let ans = numbers.reduce((total, now) => total + now);

  return ans.split('').every(item => item === '0') ? '0' : ans;
}

console.log(solution([6, 10, 2]));
console.log(solution([3, 30, 34, 5, 9]));
console.log(solution([0, 0, 0, 0, 0, 0]));
