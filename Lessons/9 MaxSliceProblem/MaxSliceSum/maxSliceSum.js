function solution(A) {
  let sum = 0;
  let max = A[0];
  let maxCell = A[0];
  for (let a of A) {
    sum = Math.max(0, sum + a);
    max = Math.max(max, sum);
    maxCell = Math.max(maxCell, a);
  }
  if (max == 0)
    return maxCell;
  return max;
}

solution([3, 2, -6, 4, 0]);
