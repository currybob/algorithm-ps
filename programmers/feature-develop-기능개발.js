// * https://programmers.co.kr/learn/courses/30/lessons/42586

function solution(progresses, speeds) {
  let remains = progresses.map((prog, idx) => Math.ceil((100 - prog) / speeds[idx]));
  let complete = [];
  let go = [];

  while (remains.length) {
    if (remains[0] <= 0) {
      go.push(remains.shift());
      continue;
    }

    if (go.length) {
      complete.push(go);
      go = [];
    }

    remains = remains.map(i => --i);
  }
  complete.push(go);

  return complete.map(comp => comp.length);
}

console.log(solution([93, 30, 55], [1, 30, 5], [2, 1]));
