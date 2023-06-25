function solution(A) {
  if (A.length == 0) { return 0; }
  let minDiff = Infinity;

  A.forEach((val, index) => A[index] = Math.abs(val));
  A.sort((a, b) => a - b);

  const max = Math.max(...A);

  const count = Array(max + 1).fill(0);

  for (let i = 0; i < A.length; i += 1) {
    count[A[i]] += 1;
  }

  const total = A.reduce((a, b) => a + b, 0);

  const dp = Array(total).fill(-1);
  dp[0] = 0;

  for (let i = 0; i < count.length; i += 1) {
    if (count[i] > 0) {
      for (let j = 0; j < dp.length; j += 1) {
        if (dp[j] >= 0) {
          dp[j] = count[i];
        } else if (j >= i && dp[j - i] > 0) {
          dp[j] = dp[j - i] - 1;
        }
        if (dp[j] >= 0) {
          if (j == (total / 2)) { return 0; }
          minDiff = Math.min(minDiff, Math.abs(total - 2 * j));
        }
      }
    }
  }
  return minDiff;
}
// console.log(solution([1, 5, 2, -2]));
