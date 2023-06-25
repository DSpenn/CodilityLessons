function solution(A) {
  let output = 0;
  let avg = 0;
  let minAvg = (A[0] + A[1]) / 2;

  for (let i = 2; i < A.length; i += 1) {
    avg = (A[i - 2] + A[i - 1] + A[i]) / 3;
    if (minAvg > avg) {
      minAvg = avg;
      output = i - 2;
    }
    avg = (A[i - 1] + A[i]) / 2;
    if (minAvg > avg) {
      minAvg = avg;
      output = i - 1;
    }
  }
  return output;
}

console.log(solution([5, 6, 3, 4, 9]));
