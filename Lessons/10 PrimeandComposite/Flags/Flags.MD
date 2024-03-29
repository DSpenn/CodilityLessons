A non-empty array A consisting of N integers is given.

A peak is an array element which is larger than its neighbours. More precisely, it is an index P such that 0 < P < N − 1 and A[P − 1] < A[P] > A[P + 1].

For example, the following array A:

    A[0] = 1
    A[1] = 5
    A[2] = 3
    A[3] = 4
    A[4] = 3
    A[5] = 4
    A[6] = 1
    A[7] = 2
    A[8] = 3
    A[9] = 4
    A[10] = 6
    A[11] = 2
has exactly four peaks: elements 1, 3, 5 and 10.

You are going on a trip to a range of mountains whose relative heights are represented by array A, as shown in a figure below. You have to choose how many flags you should take with you. The goal is to set the maximum number of flags on the peaks, according to certain rules.



Flags can only be set on peaks. What's more, if you take K flags, then the distance between any two flags should be greater than or equal to K. The distance between indices P and Q is the absolute value |P − Q|.

For example, given the mountain range represented by array A, above, with N = 12, if you take:

two flags, you can set them on peaks 1 and 5;
three flags, you can set them on peaks 1, 5 and 10;
four flags, you can set only three flags, on peaks 1, 5 and 10.
You can therefore set a maximum of three flags in this case.

Write a function:

function solution(A);

that, given a non-empty array A of N integers, returns the maximum number of flags that can be set on the peaks of the array.

For example, the following array A:

    A[0] = 1
    A[1] = 5
    A[2] = 3
    A[3] = 4
    A[4] = 3
    A[5] = 4
    A[6] = 1
    A[7] = 2
    A[8] = 3
    A[9] = 4
    A[10] = 6
    A[11] = 2
the function should return 3, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..400,000];
each element of array A is an integer within the range [0..1,000,000,000].

Javascript 100% O(N)
```javascript
function solution(A) {
  if (A.length <= 2) return 0;
  const peaks = [];
  for (let i = 1; i < A.length - 1; i += 1) {
    if (A[i - 1] < A[i] && A[i + 1] < A[i]) {
      peaks.push(i);
    }
  }

  if (peaks.length <= 2) return peaks.length;

  const maxFlag = Math.floor(Math.sqrt(peaks[peaks.length - 1] - peaks[0]) + 1);

  for (let i = maxFlag; i >= 2; i -= 1) {
    let count = 1;
    let curPos = peaks[0];
    for (let x = 1; x < peaks.length; x += 1) {
      if (curPos + i <= peaks[x]) {
        curPos = peaks[x];
        count += 1;
      }
    }
    if (count >= i) return i;
  }
}

```

Java 11 100% O(N)
```java
//import java.util.*;
import java.util.ArrayList;

class Solution {
  public int solution(int[] A) {
    if (A.length <= 2) return 0;
    ArrayList<Integer> peaks = new ArrayList<Integer>();
    for (int i = 1; i < A.length - 1; i += 1) {
      if (A[i - 1] < A[i] && A[i + 1] < A[i]) {
        peaks.add(i);
      }
    }
    if (peaks.size() <= 2) return peaks.size();
    int maxFlag = (int)Math.floor(
        Math.sqrt(peaks.get(peaks.size() - 1) - peaks.get(0)) + 1);
    int count = 1;
    int curPos = 0;
    for (int i = maxFlag; i >= 2; i -= 1) {
      count = 1;
      curPos = peaks.get(0);
      for (int x = 1; x < peaks.size(); x += 1) {
        if (curPos + i <= peaks.get(x)) {
          curPos = peaks.get(x);
          count += 1;
        }
      }
      if (count >= i) return i;
    }
    return 1;
  }
}
```


C++ 100% O(N)
```c++
#include <math.h>
#include <vector>

int solution(vector<int> &A) {
  if (A.size() <= 2) return 0;
  vector<int> peaks;
  for (int i = 1; i < A.size() - 1; i += 1) {
    if (A[i - 1] < A[i] && A[i + 1] < A[i]) {
      peaks.push_back(i);
    }
  }
  if (peaks.size() <= 2) return peaks.size();

  int maxFlag = std::round(sqrt(peaks[peaks.size() - 1] - peaks[0]) + 1);

  int count = 1;
  int curPos = peaks[0];
  for (int i = maxFlag; i >= 2; i -= 1) {
    count = 1;
    curPos = peaks[0];
    for (int x = 1; x < peaks.size(); x += 1) {
      if (curPos + i <= peaks[x]) {
        curPos = peaks[x];
        count += 1;
      }
    }
    if (count >= i) return i;
  }
}
```