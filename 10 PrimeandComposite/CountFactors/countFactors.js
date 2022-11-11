function solution(N) {
  let i = 0;
  let result = 0;

  while (i * i <= N) {
    if (N % i === 0) {
      if (i === N / i) {
        result++;
      } else {
        result += 2;
      }
    }
    i++;
  }
  return result;
}

console.log(solution(24));
