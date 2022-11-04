function solution(A) {
  if (A.length <= 2) return 0;
  const peaks = [];
  for (let i = 1; i < A.length - 1; i += 1) {
    if (A[i - 1] < A[i] && A[i + 1] < A[i]) {
      peaks.push(i);
    }
  }

  if (peaks.length <= 2) return peaks.length;

  const maxFlag = Math.floor(Math.sqrt(peaks[peaks.length - 1] - peaks[0]) + 1);

  for (let i = maxFlag; i >= 2; i -= 1) {
    let count = 1;
    let curPos = peaks[0];
    for (let x = 1; x < peaks.length; x += 1) {
      if (curPos + i <= peaks[x]) {
        curPos = peaks[x];
        count += 1;
      }
    }
    if (count >= i) return i;
  }
}

console.log(solution([1, 5, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2])); // four peaks 1, 3, 5 and 10. return 3
console.log(solution([7, 10, 4, 5, 7, 4, 6, 1, 4, 3, 3, 7]));
console.log(solution([5]));
