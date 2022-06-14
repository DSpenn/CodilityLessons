function solution(N, M) { // Integer N represents the number of chocolates
  if (N === 1) return 1;
  if (M === 1) return N;
  const gcd = (n, m) => (m === 0 ? n : gcd(m, n % m));
  return N / gcd(N, M);
}
console.time('time');
solution(10, 4); // 5 eating 0, 4, 8, 2, 6
solution(415633212, 234332);
console.timeEnd('time');
// O(log(N + M)) 
