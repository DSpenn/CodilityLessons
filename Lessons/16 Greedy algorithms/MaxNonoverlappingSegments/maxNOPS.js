function solution(A, B) {
  if (A.length == 0) return A.length;
  let count = 1;
  let ending = B[0];
  for (let x = 1; x < B.length; x += 1) {
    if (A[x] > ending) {
      ending = B[x];
      count += 1;
    }
  }
  return count;
}