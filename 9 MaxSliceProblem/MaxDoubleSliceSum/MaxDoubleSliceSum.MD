A non-empty array A consisting of N integers is given.

A triplet (X, Y, Z), such that 0 ≤ X < Y < Z < N, is called a double slice.

The sum of double slice (X, Y, Z) is the total of A[X + 1] + A[X + 2] + ... + A[Y − 1] + A[Y + 1] + A[Y + 2] + ... + A[Z − 1].

For example, array A such that:

    A[0] = 3
    A[1] = 2
    A[2] = 6
    A[3] = -1
    A[4] = 4
    A[5] = 5
    A[6] = -1
    A[7] = 2
contains the following example double slices:

double slice (0, 3, 6), sum is 2 + 6 + 4 + 5 = 17,
double slice (0, 3, 7), sum is 2 + 6 + 4 + 5 − 1 = 16,
double slice (3, 4, 5), sum is 0.
The goal is to find the maximal sum of any double slice.

Write a function:

function solution(A);

that, given a non-empty array A consisting of N integers, returns the maximal sum of any double slice.

For example, given:

    A[0] = 3
    A[1] = 2
    A[2] = 6
    A[3] = -1
    A[4] = 4
    A[5] = 5
    A[6] = -1
    A[7] = 2
the function should return 17, because no double slice of array A has a sum of greater than 17.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [3..100,000];
each element of array A is an integer within the range [−10,000..10,000].



javascript 100% O(N)
```javascript
function solution(A) {
  const sumsL = A.map(() => 0);
  const sumsR = A.map(() => 0);
  for (let left = 1, right = A.length - 2; right >= 2; left += 1, right -= 1) {
    sumsL[left] = Math.max(0, sumsL[left - 1] + A[left]);
    sumsR[right] = Math.max(0, sumsR[right + 1] + A[right]);
  }
  let max = sumsL[0] + sumsR[2];
  for (let x = 2; x < A.length - 1; x += 1) {
    max = Math.max(max, sumsL[x - 1] + sumsR[x + 1]);
  }
  return max;
}
```

Java 100% O(N)
```java
class Solution {
  public int solution(int[] A) {
    int[] sumsL = new int[A.length];
    int[] sumsR = new int[A.length];
    int max = 0;
    for (int left = 1, right = A.length - 2; right >= 2;
         left += 1, right -= 1) {
      sumsL[left] = Math.max(0, sumsL[left - 1] + A[left]);
      sumsR[right] = Math.max(0, sumsR[right + 1] + A[right]);
    }
    max = sumsL[0] + sumsR[2];
    for (int x = 2; x < A.length - 1; x += 1) {
      max = Math.max(max, sumsL[x - 1] + sumsR[x + 1]);
    }
    return max;
  }
}
```



C++ 100% O(N)
```c++
#include <limits>
int solution(vector<int> &A) {
  int sum = 0;
  int output = 0;
  int sum2 = 0;

  for (int i = 3; i < (int)A.size(); i++) {
    sum2 = max(sum2 + A[i - 2], 0);
    sum = max(sum2, sum + A[i - 1]);
    output = max(output, sum);
  }

  return output;
}
```