// * https://www.acmicpc.net/problem/10799 / 백준
// * https://programmers.co.kr/learn/courses/30/lessons/42585 / 프로그래머스

function solution(bar) {
  bar = bar.trim();

  let stackNum = 0,
    result = 0;
  last = null;

  for (const piece of bar) {
    if (piece === '(') {
      stackNum++;
    } else {
      stackNum--;
      result += last === '(' ? stackNum : 1;
    }

    last = piece;
  }

  return result;
}

console.time();
console.log(solution('(((()(()()))(())()))(()())'));
console.log(solution('()(((()())(())()))(())'));
console.timeEnd();
