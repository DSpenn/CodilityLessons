function solution(A) {
  const max = 1000000000;
  let lane = 0;
  let sum = 0;
  for (let a of A) {
    if (a === 0) lane += 1;
    else sum += lane;
    if (sum > max) return -1;
  }
  return sum;
}

console.log(solution([0, 1, 0, 1, 1]));
console.log(solution([0]));
//O(N)
