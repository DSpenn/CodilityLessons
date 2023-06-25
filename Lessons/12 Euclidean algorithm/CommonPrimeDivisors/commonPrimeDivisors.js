function solution(A, B) {
  let res = 0;
  const gcd = (n, m) => (m === 0 ? n : gcd(m, n % m));
  for (let i = 0; i < A.length; i += 1) {
    const d = gcd(A[i], B[i]);
    let c = 0;

    while (c !== 1) {
      c = gcd(A[i], d);
      A[i] /= c;
    }

    c = 0;

    while (c !== 1) {
      c = gcd(B[i], d);
      B[i] /= c;
    }

    if (A[i] == 1 && B[i] == 1) { res += 1; }
  }
  return res;
}
