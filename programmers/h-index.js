// * https://programmers.co.kr/learn/courses/30/lessons/42747
// ! 문제 설명은 이곳... https://caution-dev.tistory.com/11

// function solution(citations) {
//   citations.sort((a, b) => b - a);

//   for (let i = 0; i < citations.length; i++) {
//     if (citations[i] <= i) {
//       return i;
//     }
//   }

//   return citations.length;
// }

function solution(citations) {
  citations.sort((a, b) => b - a);
  let ans = 0;

  for (let i = 0; i < citations.length; i++) {
    if (citations[i] <= i) break;
    ans++;
  }

  return ans;
}

console.log(solution([3, 0, 6, 1, 5]));
console.log(solution([1, 7, 0, 1, 6, 4]));
console.log(solution([1545, 2, 999, 790, 540, 10, 22]));
console.log(solution([0]));
console.log(solution([7]));
