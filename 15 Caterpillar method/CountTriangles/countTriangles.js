function solution(A) {
  A.sort((a, b) => a - b);
  let count = 0;
  
  for (let i = 0; i < A.length - 2; i += 1) {
    let k = i + 2;
    for (let j = i + 1; j < A.length; j += 1) {
      while (k < A.length && A[i] + A[j] > A[k]) {
        k += 1;
        count += k - j - 1;
      }
    }
  }
  return count;
}