function solution(A) {
  A.sort((a, b) => (a - b));
  return Math.max(A[A.length - 1] * A[A.length - 2] * A[A.length - 3], A[A.length - 1] * A[0] * A[1]);
}
console.log(solution([-3, 1, 2, -2, 5, 6]));
