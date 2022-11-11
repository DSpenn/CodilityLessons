function solution(A) {
  const sumsL = new Array(A.length).fill(0);
  const sumsR = new Array(A.length).fill(0);
  for (let left = 1, right = A.length - 2; right >= 2; left += 1, right -= 1) {
    sumsL[left] = Math.max(0, sumsL[left - 1] + A[left]);
    sumsR[right] = Math.max(0, sumsR[right + 1] + A[right]);
  }
  let max = sumsL[0] + sumsR[2];
  for (let x = 2; x < A.length - 1; x += 1) {
    max = Math.max(max, sumsL[x - 1] + sumsR[x + 1]);
  }
  return max;
}

console.log(solution([3, 2, 6, -1, 4, 5, -1, 2]));