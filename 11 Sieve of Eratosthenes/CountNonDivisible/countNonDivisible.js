function solution(A) {
  const counters = Array(A.length * 2 + 1).fill(0);
  for (let x = 0; x < A.length; x += 1) counters[A[x]] += 1;

  return A.map((number) => {
    let nonDivisor = A.length;
    for (let i = 1; i * i <= number; i += 1) {
      if (number % i !== 0) continue;
      nonDivisor -= counters[i];
      if (i * i !== number) nonDivisor -= counters[number / i];
    }
    return nonDivisor;
  });
}

solution([3, 1, 2, 3, 6]); // [2, 4, 3, 2, 0]
