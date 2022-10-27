You are given N counters, initially set to 0, and you have two possible operations on them:

increase(X) − counter X is increased by 1,
max counter − all counters are set to the maximum value of any counter.
A non-empty array A of M integers is given. This array represents consecutive operations:

if A[K] = X, such that 1 ≤ X ≤ N, then operation K is increase(X),
if A[K] = N + 1 then operation K is max counter.
For example, given integer N = 5 and array A such that:

    A[0] = 3
    A[1] = 4
    A[2] = 4
    A[3] = 6
    A[4] = 1
    A[5] = 4
    A[6] = 4
the values of the counters after each consecutive operation will be:

    (0, 0, 1, 0, 0)
    (0, 0, 1, 1, 0)
    (0, 0, 1, 2, 0)
    (2, 2, 2, 2, 2)
    (3, 2, 2, 2, 2)
    (3, 2, 2, 3, 2)
    (3, 2, 2, 4, 2)
The goal is to calculate the value of every counter after all operations.

Write a function:

function solution(N, A);

that, given an integer N and a non-empty array A consisting of M integers, returns a sequence of integers representing the values of the counters.

Result array should be returned as an array of integers.

For example, given:

    A[0] = 3
    A[1] = 4
    A[2] = 4
    A[3] = 6
    A[4] = 1
    A[5] = 4
    A[6] = 4
the function should return [3, 2, 2, 4, 2], as explained above.

Write an efficient algorithm for the following assumptions:

N and M are integers within the range [1..100,000];
each element of array A is an integer within the range [1..N + 1].

javascript 100% O(N + M) 
```javascript
function solution(N, A) { // N is the number of counters
  const counters = new Array(N).fill(0);
  let max = 0;
  const len = A.length;
  let lastOpp = 0;
  for (let k = 0; k < len; k += 1) {          
    if (A[k] === N + 1) {
      if (lastOpp == 'max') {
        console.log('max')
        continue;
      } 
      for (let i = 0; i < N; i += 1) {
        counters[i] = max;
      }
      lastOpp = 'max';
    } else {
       counters[A[k] - 1] += 1; 
        if (counters[A[k] - 1] > max) {
            max = counters[A[k] - 1];
        }
        lastOpp = 'increase';
      } 
  }
  return counters;
}
console.log(solution(5, [3, 4, 4, 6, 1, 4, 4]));
console.log(solution(5, [3, 4, 4, 6, 6, 1, 4, 4]));

for (let y = 0; y < 10; y++) {
  const z = 1000000;
  console.time(`${z}`);
  const test1 = (Array.from({ length: z }, () => Math.floor(Math.random() * z)));
  solution(z,test1);
  console.timeEnd(`${z}`);
  }

```


Java 100% O(N + M)
```java
import java.util.Arrays;
class Solution {
  public int[] solution(int N, int[] A) {
    int[] counters = new int[N];
    int max = 0;
    int lastMax = 0;

    for (int k = 0; k < A.length; k++) {
      if (A[k] <= N) {
        counters[A[k] - 1] = Math.max(counters[A[k] - 1], lastMax);
        counters[A[k] - 1]++;
        max = Math.max(max, counters[A[k] - 1]);
      } else {
        lastMax = max;
      }
    }
    for (int i = 0; i < counters.length; i++) {
      counters[i] = Math.max(counters[i], lastMax);
    }
    return counters;
  }
}
```


C++ 100% O(N + M)
```c++
#include <algorithm>
#include <vector>

vector<int> solution(int N, vector<int> &A) {
  vector<int> counters(N, 0);
  int min = 0;
  int max = 0;
  for (int k = 0; k < A.size(); k++) {
    if (A[k] <= N) {
      counters[A[k] - 1] = std::max(counters[A[k] - 1], min);
      counters[A[k] - 1]++;
      max = std::max(max, counters[A[k] - 1]);
    } else {
      min = max;
    }
  }
  for (int i = 0; i < counters.size(); i++) {
    counters[i] = std::max(counters[i], min);
  }
  return counters;
}


```