function solution(A) {
  const arr = new Array(A.length);
  arr[0] = A[0];
  for (let x = 1; x < A.length; x += 1) {
    let max = arr[x - 1] + A[x];
    for (let y = 1; y <= 6; y += 1) {
      if (x - y >= 0) {
        max = Math.max(arr[x - y] + A[x], max);
      }
    }
    arr[x] = max;
  }
  return arr[A.length - 1];
}

solution([1, -2, 0, 9, -1, -2]); // returns 8
