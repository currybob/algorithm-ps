// * https://programmers.co.kr/learn/courses/30/lessons/42748

function solution(arr, commands) {
  const ans = [];

  for (const com of commands) {
    let [i, j, k] = com;
    let kth = arr.slice(i - 1, j).sort((a, b) => a - b)[k - 1];

    ans.push(kth);
  }
  return ans;
}

console.log(solution([1, 5, 2, 6, 3, 7, 4], [[2, 5, 3], [4, 4, 1], [1, 7, 3]]));
