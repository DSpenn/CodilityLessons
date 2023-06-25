function nailed(a, b, c, n) {
  const pNails = new Array(2 * c.length + 1).fill(0);
  for (let x = 0; x < n; x += 1) { pNails[c[x]] += 1; }
  for (let x = 1; x < pNails.length; x += 1) { pNails[x] += pNails[x - 1]; }
  for (let x = 0; x < a.length; x += 1) {
    if (pNails[b[x]] <= pNails[a[x] - 1]) return false;
  }
  return true;
}

function solution(A, B, C) {
  if (C.length === 1) { return A[0] <= C[0] && C[0] <= B[0] ? 1 : -1; }
  let begin = 0;
  let end = C.length - 1;
  let output = -1;

  while (begin <= end) {
    const mid = Math.floor((begin + end) / 2);
    if (nailed(A, B, C, mid + 1)) {
      end = mid - 1;
      output = mid + 1;
    } else { begin = mid + 1; }
  }
  return output;
}
//console.log(solution([1, 4, 5, 8], [4, 5, 9, 10], [4, 6, 7, 10, 2])); // 4
