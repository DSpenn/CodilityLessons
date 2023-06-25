The Fibonacci sequence is defined using the following recursive formula:

    F(0) = 0
    F(1) = 1
    F(M) = F(M - 1) + F(M - 2) if M >= 2
A small frog wants to get to the other side of a river. The frog is initially located at one bank of the river (position −1) and wants to get to the other bank (position N). The frog can jump over any distance F(K), where F(K) is the K-th Fibonacci number. Luckily, there are many leaves on the river, and the frog can jump between the leaves, but only in the direction of the bank at position N.

The leaves on the river are represented in an array A consisting of N integers. Consecutive elements of array A represent consecutive positions from 0 to N − 1 on the river. Array A contains only 0s and/or 1s:

0 represents a position without a leaf;
1 represents a position containing a leaf.
The goal is to count the minimum number of jumps in which the frog can get to the other side of the river (from position −1 to position N). The frog can jump between positions −1 and N (the banks of the river) and every position containing a leaf.

For example, consider array A such that:

    A[0] = 0
    A[1] = 0
    A[2] = 0
    A[3] = 1
    A[4] = 1
    A[5] = 0
    A[6] = 1
    A[7] = 0
    A[8] = 0
    A[9] = 0
    A[10] = 0
The frog can make three jumps of length F(5) = 5, F(3) = 2 and F(5) = 5.
the function should return 3,
Write a function:

class Solution { public int solution(int[] A); }

that, given an array A consisting of N integers, returns the minimum number of jumps by which the frog can get to the other side of the river. If the frog cannot reach the other side of the river, the function should return −1.


Write an efficient algorithm for the following assumptions:
N is an integer within the range [0..100,000];
each element of array A is an integer that can have one of the following values: 0, 1.




Javascript 100% O(N * log(N))
```javascript
function solution(A) {
  if (A.length <= 2) return 1;
  const fibArr = new Array(A.length + 2 > 30 ? 30 : A.length + 2);
  fibArr[0] = 1; fibArr[1] = 2;

  for (let i = 2; i < fibArr.length; i++) {
    fibArr[i] = fibArr[i - 1] + fibArr[i - 2];
    if (fibArr[i] == A.length + 1) return 1;
  }

  const mins = new Array(A.length + 1);
  let k = 0;
  for (let i = 0; i < mins.length; i++) {
    if (i < A.length && A[i] == 0) {
      mins[i] = -1;
      continue;
    }
    let min = Number.MAX_SAFE_INTEGER;

    for (let j = fibArr.length - 1; j >= 0; j--) {
      k = i - fibArr[j];
      if (k < -1) continue;
      if (k == -1) {
        min = 1;
        break;
      }
      if (mins[k] < 0) continue;

      if (mins[k] + 1 < min) min = mins[k] + 1;
    }
    if (min != Number.MAX_SAFE_INTEGER) mins[i] = min;
    else mins[i] = -1;
  }
  return mins[A.length];
}
//console.log(solution([0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0])); // 3

```





Java 11 100%    O(N * log(N))
```java
import java.util.Arrays;

class Solution {
  public int solution(int[] A) {
    if (A.length <= 2)
      return 1;
    int[] fibArr = new int[A.length + 2 > 30 ? 30 : A.length + 2];
    fibArr[0] = 1;
    fibArr[1] = 2;

    for (int i = 2; i < fibArr.length; i++) {
      fibArr[i] = fibArr[i - 1] + fibArr[i - 2];
      if (fibArr[i] == A.length + 1)
        return 1;
    }
    int[] mins = new int[A.length + 1];
    int k = 0;
    for (int i = 0; i < mins.length; i++) {
      if (i < A.length && A[i] == 0) {
        mins[i] = -1;
        continue;
      }
      
    int min = Integer.MAX_VALUE;

      for (int j = fibArr.length - 1; j >= 0; j--) {
        k = i - fibArr[j];
        if (k < -1)
          continue;
        if (k == -1) {
          min = 1;
          break;
        }
        if (mins[k] < 0)
          continue;

        if (mins[k] + 1 < min)
          min = mins[k] + 1;
      }
      if (min != Integer.MAX_VALUE)
        mins[i] = min;
      else
        mins[i] = -1;
    }
    return mins[A.length];
  }
}

```