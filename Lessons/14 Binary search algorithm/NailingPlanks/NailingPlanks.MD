
You are given two non-empty arrays A and B consisting of N integers. These arrays represent N planks. More precisely, A[K] is the start and B[K] the end of the K−th plank.

Next, you are given a non-empty array C consisting of M integers. This array represents M nails. More precisely, C[I] is the position where you can hammer in the I−th nail.

We say that a plank (A[K], B[K]) is nailed if there exists a nail C[I] such that A[K] ≤ C[I] ≤ B[K].

The goal is to find the minimum number of nails that must be used until all the planks are nailed. In other words, you should find a value J such that all planks will be nailed after using only the first J nails. More precisely, for every plank (A[K], B[K]) such that 0 ≤ K < N, there should exist a nail C[I] such that I < J and A[K] ≤ C[I] ≤ B[K].

For example, given arrays A, B such that:

    A[0] = 1    B[0] = 4
    A[1] = 4    B[1] = 5
    A[2] = 5    B[2] = 9
    A[3] = 8    B[3] = 10
four planks are represented: [1, 4], [4, 5], [5, 9] and [8, 10].

Given array C such that:

    C[0] = 4
    C[1] = 6
    C[2] = 7
    C[3] = 10
    C[4] = 2
if we use the following nails:

0, then planks [1, 4] and [4, 5] will both be nailed.
0, 1, then planks [1, 4], [4, 5] and [5, 9] will be nailed.
0, 1, 2, then planks [1, 4], [4, 5] and [5, 9] will be nailed.
0, 1, 2, 3, then all the planks will be nailed.
Thus, four is the minimum number of nails that, used sequentially, allow all the planks to be nailed.

Write a function:

function solution(A, B, C);

that, given two non-empty arrays A and B consisting of N integers and a non-empty array C consisting of M integers, returns the minimum number of nails that, used sequentially, allow all the planks to be nailed.

If it is not possible to nail all the planks, the function should return −1.

For example, given arrays A, B, C such that:

    A[0] = 1    B[0] = 4
    A[1] = 4    B[1] = 5
    A[2] = 5    B[2] = 9
    A[3] = 8    B[3] = 10

    C[0] = 4
    C[1] = 6
    C[2] = 7
    C[3] = 10
    C[4] = 2
the function should return 4, as explained above.

Write an efficient algorithm for the following assumptions:

N and M are integers within the range [1..30,000];
each element of arrays A, B and C is an integer within the range [1..2*M];
A[K] ≤ B[K].


Javascript 100% O((N + M) * log(M))
```javascript
function nailed(a, b, c, n) {
  const pNails = new Array(2 * c.length + 1).fill(0);
  for (let x = 0; x < n; x += 1) { pNails[c[x]] += 1; }
  for (let x = 1; x < pNails.length; x += 1) { pNails[x] += pNails[x - 1]; }
  for (let x = 0; x < a.length; x += 1) {
    if (pNails[b[x]] <= pNails[a[x] - 1]) return false;
  }
  return true;
}

function solution(A, B, C) {
  if (C.length === 1) { return A[0] <= C[0] && C[0] <= B[0] ? 1 : -1; }
  let begin = 0;
  let end = C.length - 1;
  let output = -1;

  while (begin <= end) {
    const mid = Math.floor((begin + end) / 2);
    if (nailed(A, B, C, mid + 1)) {
      end = mid - 1;
      output = mid + 1;
    } else { begin = mid + 1; }
  }
  return output;
}
//console.log(solution([1, 4, 5, 8], [4, 5, 9, 10], [4, 6, 7, 10, 2])); // 4

```


Java 11 100%  O((N + M) * log(M))
```java
import java.util.*;

class Solution {
  public int solution(int[] A, int[] B, int[] C) {
    if (C.length == 1) {
      return A[0] <= C[0] && C[0] <= B[0] ? 1 : -1;
    }
    int begin = 0;
    int end = C.length - 1;
    int output = -1;

    while (begin <= end) {
      int mid = (int) Math.floor((begin + end) / 2);
      if (nailed(A, B, C, (mid + 1))) {
        end = mid - 1;
        output = mid + 1;
      } else {
        begin = mid + 1;
      }
    }
    return output;
  }

  boolean nailed(int[] a, int[] b, int[] c, int n) {
    int[] pNails = new int[(2 * c.length + 1)];
    Arrays.fill(pNails, 0);
    for (int x = 0; x < n; x += 1) {
      pNails[c[x]] += 1;
    }
    for (int x = 1; x < pNails.length; x += 1) {
      pNails[x] += pNails[x - 1];
    }
    for (int x = 0; x < a.length; x += 1) {
      if (pNails[b[x]] <= pNails[a[x] - 1])
        return false;
    }
    return true;
  }
}

```





C++ 100%    O((N + M) * log(M))
```c++
#include <math.h>
#include <vector>

int nailed(vector<int> &a, vector<int> &b, vector<int> &c, int n) {
  vector<int> pNails(2 * c.size() + 1);
  fill(pNails.begin(), pNails.end(), 0);
  for (int x = 0; x < n; x += 1) {
    pNails[c[x]] += 1;
  }
  for (int x = 1; x < pNails.size(); x += 1) {
    pNails[x] += pNails[x - 1];
  }
  for (int x = 0; x < a.size(); x += 1) {
    if (pNails[b[x]] <= pNails[a[x] - 1]) return false;
  }
  return true;
}

int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
  if (C.size() == 1) {
    return A[0] <= C[0] && C[0] <= B[0] ? 1 : -1;
  }

  int begin = 0;
  int end = C.size() - 1;
  int output = -1;

  while (begin <= end) {
    int mid = (int)floor((begin + end) / 2);
    if (nailed(A, B, C, (mid + 1))) {
      end = mid - 1;
      output = mid + 1;
    } else {
      begin = mid + 1;
    }
  }
  return output;
}

```
