function solution(N) {
  let i = 1;
  let perimeter;

  while ((i * i) <= N) {
    if (N % i === 0) {
      perimeter = 2 * (i + N / i);
    }
    i += 1;
  }
  return perimeter;
}
solution(30);
// O(sqrt(N))
