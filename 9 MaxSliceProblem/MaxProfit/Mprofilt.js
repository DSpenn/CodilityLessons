function solution(A) {
  let maxProfit = 0;
  let minPrice = Number.MAX_SAFE_INTEGER;

  for (let i = 0; i < A.length; i += 1) {
    minPrice = Math.min(minPrice, A[i]);
    maxProfit = Math.max(maxProfit, (A[i] - minPrice));
  }
  return maxProfit;
}

solution([23171, 21011, 21123, 21366, 21013, 21367]);

// O(N)
//https://app.codility.com/demo/results/trainingX3UKXH-Y7Y/