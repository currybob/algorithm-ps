// * https://programmers.co.kr/learn/courses/30/lessons/42628

function solution(operations) {
  const queue = [];
  let ans;

  for (const opr of operations) {
    let [o, num] = opr.split(' ');
    num = parseInt(num);

    switch (o) {
      case 'I':
        queue.push(num);
        break;
      case 'D':
        let target = num > 0 ? Math.max(...queue) : Math.min(...queue);
        let idx = queue.indexOf(target);
        queue.splice(idx, 1);
    }
  }

  ans = queue.length ? [Math.max(...queue), Math.min(...queue)] : [0, 0];
  return ans;
}

console.log(solution(['I 16', 'D 1']));
console.log(solution(['I 7', 'I 5', 'I -5', 'D -1']));
console.log(solution(['I -45', 'I 653', 'D 1', 'I -642', 'I 45', 'I 97', 'D 1', 'D -1', 'I 333']));
