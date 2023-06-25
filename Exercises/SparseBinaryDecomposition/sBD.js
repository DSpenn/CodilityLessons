function solution(N) {
  const a = N & 0x55555555;
  const b = N & 0xaaaaaaaa;
  if (a + b == N) {
    return a;
  }
  return -1;
}

console.log(solution(26));
// N = 26 = 5, 10, 16 and 21. or 8, 9, 17 or 18, ?
//a = 16
//b = 10
