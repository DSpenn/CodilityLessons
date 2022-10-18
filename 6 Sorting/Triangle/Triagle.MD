An array A consisting of N integers is given. A triplet (P, Q, R) is triangular if 0 ≤ P < Q < R < N and:

A[P] + A[Q] > A[R],
A[Q] + A[R] > A[P],
A[R] + A[P] > A[Q].
For example, consider array A such that:

  A[0] = 10    A[1] = 2    A[2] = 5
  A[3] = 1     A[4] = 8    A[5] = 20
Triplet (0, 2, 4) is triangular.

Write a function:

function solution(A);

that, given an array A consisting of N integers, returns 1 if there exists a triangular triplet for this array and returns 0 otherwise.

For example, given array A such that:

  A[0] = 10    A[1] = 2    A[2] = 5
  A[3] = 1     A[4] = 8    A[5] = 20
the function should return 1, as explained above. Given array A such that:

  A[0] = 10    A[1] = 50    A[2] = 5
  A[3] = 1
the function should return 0.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].

```javascript
function solution(A)
{
  A.sort((a, b) => a - b);

  for (let x = 0; x < (A.length-2); x++) {
    const p = A[x];
    const q = A[x+1];
    const r = A[x+2];

    if ((0 <= p < q < r < A.length) && (p + q) > r && (q + r) > p && (r + p) > q)
      return 1
    
  }
  return 0;
}
//console.log(solution([10,2,5,1,8,20]));
console.log(solution([10, 50, 5, 1]));
```


Java 100%
```Java
import java.util.Arrays;

class Solution {
  public int solution(int[] A) {
    if (A.length < 3) { return 0; }

    Arrays.sort(A);
    for (int x = 2; x < A.length; x++) {
      if ((long)A[x-2] + (long)A[x-1] > (long)A[x]) { return 1; }
    }
    return 0;
  }
}
```

C++ 100% O(N*log(N))
```C++
#include <algorithm>

int solution(vector<int> &A) {
  if (A.size() < 3) { return 0; }
  sort (A.begin(), A.end());

  for (unsigned int x = 2; x < A.size(); x++) {
      if ((long long)A[x-2] + A[x-1] > A[x])  return true;
  }
  return 0;
}
```