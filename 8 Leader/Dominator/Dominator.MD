An array A consisting of N integers is given. The dominator of array A is the value that occurs in more than half of the elements of A.

For example, consider array A such that

 A[0] = 3    A[1] = 4    A[2] =  3
 A[3] = 2    A[4] = 3    A[5] = -1
 A[6] = 3    A[7] = 3
The dominator of A is 3 because it occurs in 5 out of 8 elements of A (namely in those with indices 0, 2, 4, 6 and 7) and 5 is more than a half of 8.

Write a function

function solution(A);

that, given an array A consisting of N integers, returns index of any element of array A in which the dominator of A occurs. The function should return −1 if array A does not have a dominator.

For example, given array A such that

 A[0] = 3    A[1] = 4    A[2] =  3
 A[3] = 2    A[4] = 3    A[5] = -1
 A[6] = 3    A[7] = 3
the function may return 0, 2, 4, 6 or 7, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].


Javascript 100% O(N*log(N)) or O(N)
```javascript
function solution(A) {
  const count = {};
  A.forEach(e => { count[e] = (count[e] || 0) + 1 });
  const domin = Math.max(...Object.values(count));
  const half = Math.floor(A.length / 2);
  if (domin <= half) return -1;
  for (let i = 0; i < A.length; i++) {
    if (count[A[i]] > half) return i
  }
}
```


Java 11 100%  O(N*log(N)) or O(N)
```java
import java.util.*;
class Solution {
  public int solution(int[] A) {
    if (A.length == 0) {
      return -1;
    }
    HashMap<Integer, Integer> freq = new HashMap<Integer, Integer>();
    for (int i : A) {
      if (freq.containsKey(i))
        freq.put(i, freq.get(i) + 1);
      else
        freq.put(i, 1);
    }

    int half = A.length / 2;
    int domin = Collections.max(freq.values());

    if (domin <= half)
      return -1;

    int toFind = 0;

    for (Map.Entry e : freq.entrySet()) {
      if (domin == (int) e.getValue()) {
        toFind = (int) e.getKey();
      }
    }

    for (int i = 0; i < A.length; i++) {
      if (A[i] == toFind) {
        return i;
      }
    }

    return -1;
  }
}
```







C++ 100% O(N*log(N)) or O(N)
```c++
#include <map>
#include <vector>

int solution(vector<int> &A) {
  pair<int, int> maxPair;
  map<int, int> freq;
  vector<int> B;
  for (int x : A) {
    freq[x]++;
  }

  int maxValue = 0;
  for (const auto &entry : freq) {
    if (maxValue < entry.second) {
      maxValue = entry.second;
      maxPair = entry;
    }
  }

  if (maxValue <= (A.size() / 2)) return -1;

  for (int i = 0; i < A.size(); i++) {
    if (A[i] == maxPair.first) {
      B.push_back(i);
    }
  }
  return B[0];
}

```