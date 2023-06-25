A prime is a positive integer X that has exactly two distinct divisors: 1 and X. The first few prime integers are 2, 3, 5, 7, 11 and 13.

A prime D is called a prime divisor of a positive integer P if there exists a positive integer K such that D * K = P. For example, 2 and 5 are prime divisors of 20.

You are given two positive integers N and M. The goal is to check whether the sets of prime divisors of integers N and M are exactly the same.

For example, given:

N = 15 and M = 75, the prime divisors are the same: {3, 5};
N = 10 and M = 30, the prime divisors aren't the same: {2, 5} is not equal to {2, 3, 5};
N = 9 and M = 5, the prime divisors aren't the same: {3} is not equal to {5}.
Write a function:

function solution(A, B);

that, given two non-empty arrays A and B of Z integers, returns the number of positions K for which the prime divisors of A[K] and B[K] are exactly the same.

For example, given:

    A[0] = 15   B[0] = 75
    A[1] = 10   B[1] = 30
    A[2] = 3    B[2] = 5
the function should return 1, because only one pair (15, 75) has the same set of prime divisors.

Write an efficient algorithm for the following assumptions:

Z is an integer within the range [1..6,000];
each element of arrays A and B is an integer within the range [1..2,147,483,647].

javascript 100% O(Z * log(max(A) + max(B))**2)
```javascript
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

```



C++ 100% O(Z * log(max(A) + max(B))**2)
```c++
int gcd (int a, int b) {
  if (a % b == 0) return b;
  else return gcd (b, a%b);
}

int solution(vector<int> &A, vector<int> &B) {
    int resCount = 0;
  for (unsigned int i = 0; i < A.size(); i += 1) {
    int a = A[i];
    int b = B[i];
    int d = gcd(a, b);
    int c = 0;

    while (c != 1) {
      c = gcd(a, d);
      a /= c;
    }

    c = 0;

    while (c != 1) {
      c = gcd(b, d);
      b /= c;
    }

    if (a == 1 && b == 1) {
      resCount += 1;
    }
  }
  return resCount;
}
```