function solution(A, K) {
  if (!A.length) return [];
  for (let i = 0; i < K; i++) {
    const tail = A[A.length - 1];
    console.log(A[A.length - 1]);
    console.log('tail', tail);
    A.pop();
    A.unshift(tail);
  }
  return A;
}

console.log(solution([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 3));
console.log(solution([3, 8, 9, 7, 6], 3));
