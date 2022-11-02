An integer M and a non-empty array A consisting of N non-negative integers are given. All integers in array A are less than or equal to M.

A pair of integers (P, Q), such that 0 ≤ P ≤ Q < N, is called a slice of array A. The slice consists of the elements A[P], A[P + 1], ..., A[Q]. A distinct slice is a slice consisting of only unique numbers. That is, no individual number occurs more than once in the slice.

For example, consider integer M = 6 and array A such that:

    A[0] = 3
    A[1] = 4
    A[2] = 5
    A[3] = 5
    A[4] = 2
There are exactly nine distinct slices: (0, 0), (0, 1), (0, 2), (1, 1), (1, 2), (2, 2), (3, 3), (3, 4) and (4, 4).

The goal is to calculate the number of distinct slices.

Write a function:

function solution(M, A);

that, given an integer M and a non-empty array A consisting of N integers, returns the number of distinct slices.

If the number of distinct slices is greater than 1,000,000,000, the function should return 1,000,000,000.

For example, given integer M = 6 and array A such that:

    A[0] = 3
    A[1] = 4
    A[2] = 5
    A[3] = 5
    A[4] = 2
the function should return 9, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
M is an integer within the range [0..100,000];
each element of array A is an integer within the range [0..M].



javascript 100%  O(N) 
```javascript
function solution(M, A) {
  if (A.length === 1) return 1;
  const LIMIT = 1000000000;
  let count = 0;
  let start = 0;
  const lastPos = new Array(M + 1).fill(-1);
  
  for (let i = 0; i < A.length; i += 1) {
    if (lastPos[A[i]] + 1 > start) {
      start = lastPos[A[i]] + 1;
    }
    lastPos[A[i]] = i;
    count += i - start + 1;

    if (count > LIMIT) break;
  }
  return count > LIMIT ? LIMIT: count;
}

```

Java 100% O(N)
```java
import java.util.Arrays;

class Solution {
  public int solution(int M, int[] A) {
    if (A.length == 1)
      return 1;

    // Arrays.sort(A);
    int[] B = new int[M + 1];
    Arrays.fill(B, -1);

    int count = 0;
    int start = 0;
    int LIMIT = 1000000000;
    // System.out.println(Arrays.toString(B));
    for (int i = 0; i < A.length; i++) {
      if (B[A[i]] + 1 > start) {
        start = B[A[i]] + 1;
      }
      B[A[i]] = i;
      count += i - start + 1;

      if (count > LIMIT)
        break;
    }
    return count > LIMIT ? LIMIT : count;
  }
}
```





C++ 100% O(N)
```c++
#include <algorithm>
#include <vector>

int solution(int M, vector<int> &A) {
  if (A.size() == 1) return 1;
  int LIMIT = 1000000000;
  vector<int> lastPos(M + 1, 0);
  fill(lastPos.begin(), lastPos.end(), -1);
  int count = 0;
  int start = 0;

  for (size_t i = 0; i < A.size(); i += 1) {
    if (lastPos[A[i]] + 1 > start) {
      start = lastPos[A[i]] + 1;
    }
    lastPos[A[i]] = i;
    count += i - start + 1;

    if (count > LIMIT) break;
  }
  return count > LIMIT ? LIMIT : count;
}
```