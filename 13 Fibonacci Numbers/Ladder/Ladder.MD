

You have to climb up a ladder. The ladder has exactly N rungs, numbered from 1 to N. With each step, you can ascend by one or two rungs. More precisely:

        with your first step you can stand on rung 1 or 2,
        if you are on rung K, you can move to rungs K + 1 or K + 2,
        finally you have to stand on rung N.

Your task is to count the number of different ways of climbing to the top of the ladder.

For example, given N = 4, you have five different ways of climbing, ascending by:

        1, 1, 1 and 1 rung,
        1, 1 and 2 rungs,
        1, 2 and 1 rung,
        2, 1 and 1 rungs, and
        2 and 2 rungs.

Given N = 5, you have eight different ways of climbing, ascending by:

        1, 1, 1, 1 and 1 rung,
        1, 1, 1 and 2 rungs,
        1, 1, 2 and 1 rung,
        1, 2, 1 and 1 rung,
        1, 2 and 2 rungs,
        2, 1, 1 and 1 rungs,
        2, 1 and 2 rungs, and
        2, 2 and 1 rung.

The number of different ways can be very large, so it is sufficient to return the result modulo 2P, for a given integer P.

Write a function:

    function solution(A, B);

that, given two non-empty arrays A and B of L integers, returns an array consisting of L integers specifying the consecutive answers; position I should contain the number of different ways of climbing the ladder with A[I] rungs modulo 2B[I].

For example, given L = 5 and:
    A[0] = 4   B[0] = 3
    A[1] = 4   B[1] = 2
    A[2] = 5   B[2] = 4
    A[3] = 5   B[3] = 3
    A[4] = 1   B[4] = 1

the function should return the sequence [5, 1, 8, 0, 1], as explained above.

Write an efficient algorithm for the following assumptions:

        L is an integer within the range [1..50,000];
        each element of array A is an integer within the range [1..L];
        each element of array B is an integer within the range [1..30].



javascript 100% O(L) 
```javascript
function solution(A, B) {
  const aLen = A.length;
  const result = [];
  let max = 0;
  const steps = [1, 1];
  let maxB = 0;

  for (let i = 0; i < aLen; i += 1) {
    max = Math.max(max, A[i]);
    maxB = Math.max(maxB, B[i]);
  }

  let y = 1;
  while ((y += 1) <= max) {
    steps[y] = (steps[y - 1] + steps[y - 2]) % (2 ** maxB);
  }

  for (let x = 0; x < aLen; x += 1) {
    const div = steps[A[x]] & (2 ** B[x] - 1);
    result.push(div);
  }

  return result;
}
```

Java 100% O(L)
```java
import java.util.Arrays;

class Solution {
  public int[] solution(int[] A, int[] B) {
    int[] result = new int[A.length];
    int[] steps = new int[A.length + 1];
    steps[0] = 1;
    steps[1] = 1;

    int max = Arrays.stream(A).max().getAsInt();
    int maxB = Arrays.stream(B).max().getAsInt();

    int y = 1;
    while ((y += 1) <= max) {
      steps[y] = (steps[y - 1] + steps[y - 2]) % (int) Math.pow(2, maxB);
    }

    for (int x = 0; x < A.length; x += 1) {
      int div = (int) Math.pow(2, B[x]) - 1;
      result[x] = steps[A[x]] & div;
    }

    return result;
  }
}
```





C++ 100%    O(L)
```c++
#include <bits/stdc++.h>
#include <math.h>
#include <vector>
vector<int> solution(vector<int> &A, vector<int> &B) {
  int L = A.size();
  vector<int> result(L);
  int maxB = *std::max_element(B.begin(), B.end());
  int max = *std::max_element(A.begin(), A.end());
  vector<int> modules(L, 0);

  for (int i = 0; i < L; i++) {
    modules[i] = (1 << B[i]) - 1;
  }

  vector<int> fibs;
  fibs.push_back(0);
  fibs.push_back(1);
  for (int i = 2; i < L + 2; i++) {
    fibs.push_back(fibs[i - 1] + fibs[i - 2]);
  }

  for (auto x = 0; x < L; x += 1) {
    result[x] = (fibs[A[x] + 1] & modules[x]);
  }

  return result;
}
```