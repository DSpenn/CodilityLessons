Let A be a non-empty array consisting of N integers.

The abs sum of two for a pair of indices (P, Q) is the absolute value |A[P] + A[Q]|, for 0 ≤ P ≤ Q < N.

For example, the following array A:

  A[0] =  1
  A[1] =  4
  A[2] = -3
has pairs of indices (0, 0), (0, 1), (0, 2), (1, 1), (1, 2), (2, 2).
The abs sum of two for the pair (0, 0) is A[0] + A[0] = |1 + 1| = 2.
The abs sum of two for the pair (0, 1) is A[0] + A[1] = |1 + 4| = 5.
The abs sum of two for the pair (0, 2) is A[0] + A[2] = |1 + (−3)| = 2.
The abs sum of two for the pair (1, 1) is A[1] + A[1] = |4 + 4| = 8.
The abs sum of two for the pair (1, 2) is A[1] + A[2] = |4 + (−3)| = 1.
The abs sum of two for the pair (2, 2) is A[2] + A[2] = |(−3) + (−3)| = 6.
Write a function:

function solution(A);

that, given a non-empty array A consisting of N integers, returns the minimal abs sum of two for any pair of indices in this array.

For example, given the following array A:

  A[0] =  1
  A[1] =  4
  A[2] = -3
the function should return 1, as explained above.

Given array A:

  A[0] = -8
  A[1] =  4
  A[2] =  5
  A[3] =-10
  A[4] =  3
the function should return |(−8) + 5| = 3.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000,000..1,000,000,000].






javascript 100%  O(N * log(N))
```javascript
function solution(A) {
  A.sort((a, b) => a - b);
  const test = [];
  let start = 0;
  let end = A.length - 1;
  let minAbsSum = Math.abs(A[start] + A[end]);
  while (start <= end) {
    const currentSum = A[start] + A[end];
    test.push(`$ {start},$ {end}`);
    if (currentSum == 0) return 0;
    minAbsSum = Math.min(minAbsSum, Math.abs(currentSum));
    if (currentSum <= 0) {
      start += 1;
    } else {
      end -= 1;
    }
  }
  return minAbsSum;
}

```


Java 11 100% O(N * log(N))

```java
import java.util.Arrays;

class Solution {
  public int solution(int[] A) {
    Arrays.sort(A);
    int start = 0;
    int end = A.length - 1;
    int currentSum = 0;
    int minAbsSum = Math.abs(A[start] + A[end]);
    while (start <= end) {
      currentSum = A[start] + A[end];
      if (currentSum == 0) return 0;
      minAbsSum = Math.min(minAbsSum, Math.abs(currentSum));
      if (currentSum <= 0) {
        start += 1;
      } else {
        end -= 1;
      }
    }
    return minAbsSum;
  }
}
```


C++ 100% O(N * log(N))
```c++
#include <algorithm>
#include <cmath>

int solution(vector<int> &A) {
  sort(A.begin(), A.end());
  int start = 0;
  int end = A.size() - 1;
  int currentSum = 0;
  int minAbsSum = abs(A[start] + A[end]);
  while (start <= end) {
    currentSum = A[start] + A[end];
    if (currentSum == 0) return 0;
    minAbsSum = min(minAbsSum, abs(currentSum));
    if (currentSum <= 0) {
      start += 1;
    } else {
      end -= 1;
    }
  }
  return minAbsSum;
}
```