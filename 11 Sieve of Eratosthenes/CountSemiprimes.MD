A prime is a positive integer X that has exactly two distinct divisors: 1 and X. The first few prime integers are 2, 3, 5, 7, 11 and 13.

A semiprime is a natural number that is the product of two (not necessarily distinct) prime numbers. The first few semiprimes are 4, 6, 9, 10, 14, 15, 21, 22, 25, 26.

You are given two non-empty arrays P and Q, each consisting of M integers. These arrays represent queries about the number of semiprimes within specified ranges.

Query K requires you to find the number of semiprimes within the range (P[K], Q[K]), where 1 ≤ P[K] ≤ Q[K] ≤ N.

For example, consider an integer N = 26 and arrays P, Q such that:

    P[0] = 1    Q[0] = 26
    P[1] = 4    Q[1] = 10
    P[2] = 16   Q[2] = 20
The number of semiprimes within each of these ranges is as follows:

(1, 26) is 10,
(4, 10) is 4,
(16, 20) is 0.
Write a function:

function solution(N, P, Q);

that, given an integer N and two non-empty arrays P and Q consisting of M integers, returns an array consisting of M elements specifying the consecutive answers to all the queries.

For example, given an integer N = 26 and arrays P, Q such that:

    P[0] = 1    Q[0] = 26
    P[1] = 4    Q[1] = 10
    P[2] = 16   Q[2] = 20
the function should return the values [10, 4, 0], as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..50,000];
M is an integer within the range [1..30,000];
each element of arrays P and Q is an integer within the range [1..N];
P[i] ≤ Q[i].

```javascript
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
      semiPrime[y] = semiPCount+1;
      semiPCount += 1;
    } else semiPrime[y] = semiPCount;
  }
  for (let x = 0; x < P.length; x += 1) {
    //const rangeCount = semiPrime[Q[x]] - semiPrime[P[x] - 1];
    outputArr.push(semiPrime[Q[x]] - semiPrime[P[x] - 1]);
  }
  console.log(outputArr);
  return outputArr;
}

solution(26, [1, 4, 16], [26, 10, 20]); // [10, 4, 0]
//O(N * log(log(N)) + M)


```