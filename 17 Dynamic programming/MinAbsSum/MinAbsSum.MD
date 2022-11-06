For a given array A of N integers and a sequence S of N integers from the set {−1, 1}, we define val(A, S) as follows:

val(A, S) = |sum{ A[i]*S[i] for i = 0..N−1 }|

(Assume that the sum of zero elements equals zero.)

For a given array A, we are looking for such a sequence S that minimizes val(A,S).

Write a function:

function solution(A);

that, given an array A of N integers, computes the minimum value of val(A,S) from all possible values of val(A,S) for all possible sequences S of N integers from the set {−1, 1}.

For example, given array:

  A[0] =  1
  A[1] =  5
  A[2] =  2
  A[3] = -2
your function should return 0, since for S = [−1, 1, −1, 1], val(A, S) = 0, which is the minimum possible value.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..20,000];
each element of array A is an integer within the range [−100..100].

Javascript 100%  O(N * max(abs(A))**2)
```javascript
function solution(A) {
  if (A.length == 0) { return 0; }
  let minDiff = Infinity;

  A.forEach((val, index) => A[index] = Math.abs(val));
  A.sort((a, b) => a - b);

  const max = Math.max(...A);

  const count = Array(max + 1).fill(0);

  for (let i = 0; i < A.length; i += 1) {
    count[A[i]] += 1;
  }

  const total = A.reduce((a, b) => a + b, 0);

  const dp = Array(total).fill(-1);
  dp[0] = 0;

  for (let i = 0; i < count.length; i += 1) {
    if (count[i] > 0) {
      for (let j = 0; j < dp.length; j += 1) {
        if (dp[j] >= 0) {
          dp[j] = count[i];
        } else if (j >= i && dp[j - i] > 0) {
          dp[j] = dp[j - i] - 1;
        }
        if (dp[j] >= 0) {
          if (j == (total / 2)) { return 0; }
          minDiff = Math.min(minDiff, Math.abs(total - 2 * j));
        }
      }
    }
  }
  return minDiff;
}

```