int solution(int N) {
  int i = 1;
  int perimeter = 0;

  while ((i * i) <= N) {
    if (N % i == 0) {
      perimeter = 2 * (i + N / i);
    }
    i += 1;
  }
  return perimeter;
}
