An array A consisting of N integers is given. A triplet (P, Q, R) is triangular if it is possible to build a triangle with sides of lengths A[P], A[Q] and A[R]. In other words, triplet (P, Q, R) is triangular if 0 ≤ P < Q < R < N and:

A[P] + A[Q] > A[R],
A[Q] + A[R] > A[P],
A[R] + A[P] > A[Q].
For example, consider array A such that:

  A[0] = 10    A[1] = 2    A[2] = 5
  A[3] = 1     A[4] = 8    A[5] = 12
There are four triangular triplets that can be constructed from elements of this array, namely (0, 2, 4), (0, 2, 5), (0, 4, 5), and (2, 4, 5).

Write a function:

function solution(A);

that, given an array A consisting of N integers, returns the number of triangular triplets in this array.

For example, given array A such that:

  A[0] = 10    A[1] = 2    A[2] = 5
  A[3] = 1     A[4] = 8    A[5] = 12
the function should return 4, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..1,000];
each element of array A is an integer within the range [1..1,000,000,000].


JavaScript 100% O(N**2)
```javascript
function solution(A) {
  A.sort((a, b) => a - b);
  let count = 0;
  
  for (let i = 0; i < A.length - 2; i += 1) {
    let k = i + 2;
    for (let j = i + 1; j < A.length; j += 1) {
      while (k < A.length && A[i] + A[j] > A[k]) {
        k += 1;
        count += k - j - 1;
      }
    }
  }
  return count;
}
```

Java 11 100% O(N**2)
```java
import java.util.Arrays;

class Solution {
  public int solution(int[] A) {
    Arrays.sort(A);
    int count = 0;
    int k = 0;
    for (int i = 0; i < A.length - 2; i += 1) {
      k = i + 2;
      for (int j = i + 1; j < A.length; j++) {
        while (k < A.length && A[i] + A[j] > A[k]) {
          k += 1;
          count += k - j - 1;
        }
      }
    }
    return count;
  }
}
```

C++ 100%  O(N**2)
```c++
#include <algorithm>
#include <vector>

int solution(vector<int> &A) {
  std::sort(A.begin(), A.end());
  int count = 0;
  int k = 0;
  for (int i = 0; i < A.size() - 2; i += 1) {
    k = i + 2;
    for (int j = i + 1; j < A.size(); j++) {
      while (k < A.size() && A[i] + A[j] > A[k]) {
        k += 1;
        count += k - j - 1;
      }
    }
  }
  return count;
}
```