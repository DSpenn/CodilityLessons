function solution(A) {
  if (A.length < 3) return 0;
  const peaks = [];

  for (let i = 1; i < A.length - 1; i += 1) {
    if (A[i] > A[i - 1] && A[i] > A[i + 1]) peaks.push(i);
  }
  if (peaks.length === 0) return 0;

  for (let i = peaks.length; i >= 2; i -= 1) {
    if (A.length % i === 0) {
      const K = A.length / i;
      let x = 0;
      for (const i in peaks) {
        const start = x * K;
        const end = (x + 1) * K;
        if (peaks[i] >= start && peaks[i] < end) { x += 1; }
      }
      if (x === i) return i;
    }
  }
  return 1;
}

//solution([1, 2, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2]); // 3
