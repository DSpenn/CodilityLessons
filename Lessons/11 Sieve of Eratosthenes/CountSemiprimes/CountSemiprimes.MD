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


O(N * log(log(N)) + M)
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
    outputArr.push(semiPrime[Q[x]] - semiPrime[P[x] - 1]);
  }
  console.log(outputArr);
  return outputArr;
}

solution(26, [1, 4, 16], [26, 10, 20]); // [10, 4, 0]

```

Java 11 100% O(N * log(log(N)) + M)
```java
import java.util.Arrays;

class Solution {
  public int[] solution(int N, int[] P, int[] Q) {
    int[] semiPrime = new int[N + 1];
    int[] output = new int[P.length];
    int semiPCount = 0;
    for (int y = 0; y <= N; y++) {
      if (isSemiPrime(y)) {
        semiPrime[y] = semiPCount + 1;
        semiPCount += 1;
      } else
        semiPrime[y] = semiPCount;
    }

    for (int x = 0; x < P.length; x++) {
      output[x] = semiPrime[Q[x]] - semiPrime[P[x] - 1];
    }
    return output;
  }

  boolean isSemiPrime(int nn) {
    int num = nn;
    int cnt = 0;
    int boundary = (int) Math.sqrt(num);
    for (int i = 2; cnt < 2 && i <= boundary; i++) {
      while (num % i == 0) {
        num /= i;
        cnt++;
      }
    }
    if (num > 1)
      cnt++;
    return cnt == 2;
  }
}

```



C++ 100% O(N * log(log(N)) + M)
```c++
#include <math.h>
#include <vector>
int isSemiPrime(int nn) {
  int num = nn;
  int cnt = 0;
  int boundary = std::round(sqrt(num));
  for (auto i = 2; cnt < 2 && i <= boundary; i++) {
    while (num % i == 0) {
      num /= i;
      cnt++;
    }
  }
  if (num > 1) cnt++;
  return cnt == 2;
}
// 0, 0, 0, 0, 1, 1, 2, 2, 2, 3, 4, 4, 4, 4, 5, 6, 6, 6, 6, 6, 6, 7, 8, 8, 8, 9, 10

vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
  vector<int> semiPrime(N + 1);
  vector<int> output(P.size());
  int semiPCount = 0;
  for (auto y = 0; y <= N; y++) {
    if (isSemiPrime(y)) {
      semiPrime[y] = semiPCount + 1;
      semiPCount += 1;
    } else
      semiPrime[y] = semiPCount;
  }
  
  for (auto x = 0; x < P.size(); x++) {
    output[x] = semiPrime[Q[x]] - semiPrime[P[x] - 1];
  }
  return output;
}


```