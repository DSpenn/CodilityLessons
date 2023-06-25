function isSemiPrime(n) {
  let num = n;
  let cnt = 0;
  const boundary = Math.floor(Math.sqrt(n));
  for (let i = 2; cnt < 2 && i <= boundary; i += 1) {
    while (num % i === 0) {
      num /= i;
      cnt += 1;
    }
  }
  if (num > 1) cnt += 1;
  return cnt === 2;
}

function solution(N, P, Q) {
  const semiPrime = [];
  const outputArr = [];
  let semiPCount = 0;
  for (let y = 0; y <= N; y += 1) {
    if (isSemiPrime(y)) {
      semiPrime[y] = semiPCount + 1;
      semiPCount += 1;
    } else semiPrime[y] = semiPCount;
  }
  console.log(semiPrime);
  for (let x = 0; x < P.length; x += 1) {
    //console.log('Q[x]', Q[x], ' ', semiPrime[Q[x]], '  ', P[x], '  ', semiPrime[P[x] - 1]);
    outputArr.push(semiPrime[Q[x]] - semiPrime[P[x] - 1]);
  }
  console.log(outputArr);
  return outputArr;
}

solution(26, [1, 4, 16], [26, 10, 20]); // [10, 4, 0]
