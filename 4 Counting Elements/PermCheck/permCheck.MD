A non-empty array A consisting of N integers is given.

A permutation is a sequence containing each element from 1 to N once, and only once.

For example, array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2
is a permutation, but array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
is not a permutation, because value 2 is missing.

The goal is to check whether array A is a permutation.

Write a function:

function solution(A);

that, given an array A, returns 1 if array A is a permutation and 0 if it is not.

For example, given array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2
the function should return 1.

Given array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
the function should return 0.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [1..1,000,000,000].


```javascript
function solution(A) {

  A.sort((a, b) => a - b);
  const uniqueCheck = new Set(A);
  //const unique = [...new Set(A)];
  //if (unique.length !== A.length) {
  if (uniqueCheck.size !== A.length) {
      return 0;
  }

  for (var i =0; i < A.length; i += 1) {
      if(A[i] !== (i + 1)) {
          return 0;
      }
  }
  return 1;
}

solution([4, 1, 3, 2, 5, 6, 7, 11, 9, 10, 8]);
solution([4, 1, 3]);
solution([4, 1, 3 , 3]);

```



Java 100%
```Java
import java.util.Arrays;

class Solution {
  public int solution(int[] A) {
    Arrays.sort(A);
    for(int i=0; i< A.length; i++)
    {
      if(A[i] != (i + 1)) {
        return 0;
        }
    }
    return 1;
  }
}
```


C++ 100% O(N) or O(N * log(N))
```C++
#include <algorithm>
int solution(vector<int> &A) {

  sort(A.begin(), A.end());
  for(int i=0; i< A.size(); i++)
    {
      if(A[i] != (i + 1)) {
        return 0;
      }
    }
  return 1;
}
```