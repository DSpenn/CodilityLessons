function solution(A, B) {
  const aLen = A.length;
  const result = [];
  let max = 0;
  const steps = [1, 1];
  let maxB = 0;

  for (let i = 0; i < aLen; i += 1) {
    max = Math.max(max, A[i]);
    maxB = Math.max(maxB, B[i]);
  }

  let y = 1;
  while ((y += 1) <= max) {
    steps[y] = (steps[y - 1] + steps[y - 2]) % (2 ** maxB);
  }

  for (let x = 0; x < aLen; x += 1) {
    const div = steps[A[x]] & (2 ** B[x] - 1);
    result.push(div);
  }

  return result;
}

solution([4, 4, 5, 5, 1], [3, 2, 4, 3, 1]); // [5, 1, 8, 0, 1],
