function solution(A) {
  A.sort((a, b) => a - b);
  const test = [];
  let start = 0;
  let end = A.length - 1;
  let minAbsSum = Math.abs(A[start] + A[end]);
  while (start <= end) {
    const currentSum = A[start] + A[end];
    test.push(`$ {start},$ {end}`);
    if (currentSum == 0) return 0;
    minAbsSum = Math.min(minAbsSum, Math.abs(currentSum));
    if (currentSum <= 0) {
      start += 1;
    } else {
      end -= 1;
    }
  }
  return minAbsSum;
}