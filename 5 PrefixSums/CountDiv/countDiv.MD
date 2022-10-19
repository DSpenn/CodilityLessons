Write a function:

function solution(A, B, K);

that, given three integers A, B and K, returns the number of integers within the range [A..B] that are divisible by K, i.e.:

{ i : A ≤ i ≤ B, i mod K = 0 }

For example, for A = 6, B = 11 and K = 2, your function should return 3, because there are three numbers divisible by 2 within the range [6..11], namely 6, 8 and 10.

Write an efficient algorithm for the following assumptions:

A and B are integers within the range [0..2,000,000,000];
K is an integer within the range [1..2,000,000,000];
A ≤ B.

```javascript
function solution(A, B, K)
{
  console.log('Math.floor(B/K)',Math.floor(B/K));
  console.log('Math.floor((A-1)/K', Math.floor((A-1)/K));
  return (Math.floor(B/K) - Math.floor((A-1)/K));
}

console.log(solution(6,11,2)) //should return 3

```

Java 100% O(1)
```Java
class Solution {
  public int solution(int A, int B, int K) {
    if (A % K == 0) {
      return B / K - A / K + 1;
    }
    return B / K - A / K;
  }
}
```

C++ 100% O(1)
```C++
int solution(int A, int B, int K) {
  if (A % K == 0) {
    return B / K - A / K + 1;
  }
  return B / K - A / K;
}

```