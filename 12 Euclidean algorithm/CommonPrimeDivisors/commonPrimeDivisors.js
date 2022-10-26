function solution(A, B) {
  const gcd = (n, m) => (m === 0 ? n : gcd(m, n % m));
  let resCount = 0;

  for (let i = 0; i < A.length; i += 1) {
    let a = A[i];
    let b = B[i];
    const d = gcd(a, b);
    let c = 0;

    while (c !== 1) {
      c = gcd(a, d);
      a /= c;
    }

    c = 0;

    while (c !== 1) {
      c = gcd(b, d);
      b /= c;
    }

    if (a == 1 && b == 1) {
      resCount += 1;
    }
  }
  return resCount;
}
