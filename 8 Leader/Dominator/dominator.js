function solution(A) {
  const count = {};
  A.forEach(e => { count[e] = (count[e] || 0) + 1 });
  console.log(count);
  const domin = Math.max(...Object.values(count));
  const half = Math.floor(A.length / 2);
  if (domin <= half) return -1;
  for (let i = 0; i < A.length; i++) {
    if (count[A[i]] > half) return i
  }
}
//console.log(solution([2, 2, 2, 2, 3, 3, 3, 3]));
console.log(solution([3, 4, 3, 2, 3, -1, 3, 3]));