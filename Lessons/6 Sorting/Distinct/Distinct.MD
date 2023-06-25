Write a function
function solution(A);

that, given an array A consisting of N integers, returns the number of distinct values in array A.

For example, given array A consisting of six elements such that:

 A[0] = 2    A[1] = 1    A[2] = 1
 A[3] = 2    A[4] = 3    A[5] = 1
the function should return 3, because there are 3 distinct values appearing in array A, namely 1, 2 and 3.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].

```javascript
function solution(A) {
  const distinctSet = new Set(A);
  return distinctSet.size;
}
console.log(solution([2, 1, 1, 2, 3, 1]));

```

Java
```java
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Solution {
  public int solution(int[] A) {
    if (A.length == 0) {
      return 0;
    }

    Set<Integer> Set = new HashSet<>();
    for (int element : A) {
      Set.add(element);
    }
    return Set.size();
  }
}
```

C++ 100% O(N*log(N)) or O(N)
```C++
#include <algorithm>
#include <vector>

int solution(vector<int> &A) {
  sort(A.begin(), A.end());
  A.erase(unique(A.begin(), A.end()), A.end());
  return A.size();
}
```