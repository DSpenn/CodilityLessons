function solution(A) {
  let min = Number.POSITIVE_INFINITY;
  let diff = A.reduce((a, b) => a + b); // total sum of all numbers in input.

  for (let i = 0; i < A.length - 1; i++) {
    diff -= 2 * A[i];
    if (min > Math.abs(diff)) {
      min = Math.abs(diff);
    }
  }
  return min;
}

//console.log(solution([3, 1, 2 , 4, 3]));
