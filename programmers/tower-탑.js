// * https://programmers.co.kr/learn/courses/30/lessons/42588

// function solution(heights) {
//   const func = (total, now, idx) => {
//     const target = heights
//       .slice(0, idx)
//       .reverse()
//       .find(i => i > now);

//     const targetIdx = heights.lastIndexOf(target) + 1;
//     total.unshift(targetIdx);
//     heights.pop();

//     return total;
//   };

//  return heights.reduceRight(func, []);
// }

// ! 더 쉬운 방법....

function solution(heights) {
  return heights.map((v, i, e) => {
    for (--i; i > -1; i--) {
      if (e[i] > v) break;
    }

    return ++i;
  });
}

console.log(solution([6, 9, 5, 7, 4]));
console.log(solution([3, 9, 9, 3, 5, 7, 2]));
console.log(solution([1, 5, 3, 6, 7, 6, 5]));
